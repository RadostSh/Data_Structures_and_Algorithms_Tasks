#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Comparator {
    long long X;
    long long Y;
    long long distance;

    bool operator<(const Comparator& other) const {
        if (distance != other.distance) {
            return distance > other.distance;
        }
        else if (X != other.X) {
            return X > other.X;
        }
        else {
            return Y > other.Y;
        }
    }
};

int main() {
    long long X, Y, N, K;
    cin >> X >> Y >> N >> K;

    priority_queue<Comparator> pq;
    long long currX, currY;
    for (long long i = 0; i < N; i++) {
        cin >> currX >> currY;
        long long powX = (X - currX) * (X - currX);
        long long powY = (Y - currY) * (Y - currY);
        pq.push({ currX, currY, powX + powY });
    }

    for (long long i = 0; i < K; i++) {
        Comparator temp = pq.top();
        pq.pop();
        cout << temp.X << " " << temp.Y << endl;
    }

    return 0;
}