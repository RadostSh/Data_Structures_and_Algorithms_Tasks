#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Guest {
    size_t arrival;
    size_t dep;
    size_t index;
    size_t seat;

    bool operator<(const Guest& other) const
    {
        return arrival > other.arrival;
    }

    bool operator>(const Guest& other) const
    {
        return dep > other.dep;
    }
};

int main() {
    size_t N, start, end, T;
    cin >> N;
    priority_queue<Guest, vector<Guest>, less<Guest>> arrivals;
    for (size_t i = 0; i < N; i++)
    {
        cin >> start >> end;
        arrivals.push({ start, end, i, 0 });
    }
    cin >> T;

    priority_queue<size_t, vector<size_t>, greater<size_t>> freeSeats;
    for (size_t i = 0; i < N; i++)
    {
        freeSeats.push(i);
    }

    priority_queue<Guest, vector<Guest>, greater<Guest>> departures;
    while (!arrivals.empty())
    {
        while (!departures.empty() && departures.top().dep <= arrivals.top().arrival)
        {
            freeSeats.push(departures.top().seat);
            departures.pop();
        }

        Guest curr = arrivals.top();
        arrivals.pop();
        curr.seat = freeSeats.top();
        freeSeats.pop();
        departures.push(curr);

        if (curr.index == T) {
            cout << curr.seat;
            break;
        }
    }

    return 0;
}