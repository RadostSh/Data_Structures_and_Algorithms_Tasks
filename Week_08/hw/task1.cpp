#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Group
{
    size_t arrival;
    size_t dep;
    size_t people;

    bool operator<(const Group& other) const
    {
        return arrival > other.arrival;
    }

    bool operator>(const Group& other) const
    {
        return dep > other.dep;
    }
};

int main() {
    size_t Q;
    cin >> Q;
    for (size_t i = 0; i < Q; i++)
    {
        size_t start, end, people, N, C;
        cin >> N >> C;

        priority_queue<Group> arrivals;
        for (size_t j = 0; j < N; j++)
        {
            cin >> people >> start >> end;
            arrivals.push({start, end, people});
        }

        priority_queue<Group, vector<Group>, greater<Group>> departures;
        size_t currCount = 0;
        bool canSeat = true;
        while (!arrivals.empty()) {
            while (!departures.empty() && departures.top().dep <= arrivals.top().arrival) {
                currCount -= departures.top().people;
                departures.pop();
            }

            currCount += arrivals.top().people;
            departures.push(arrivals.top());
            arrivals.pop();

            if (currCount > C) {
                canSeat = false;
                break;
            }
        }
        cout << canSeat << endl;
    }

    return 0;
}