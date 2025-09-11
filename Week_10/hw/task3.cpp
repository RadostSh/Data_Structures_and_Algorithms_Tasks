#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 1e6 + 1;
vector<vector<pair<int, pair<int, int>>>> graph(MAX_SIZE);
vector<int> dist(MAX_SIZE);

bool dijkstra(int startV, int endV, int maxTime, int maxW) {
    fill(dist.begin(), dist.end(), INT_MAX);
    dist[startV] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, startV});
    
    while (!pq.empty()) {
        int currT = pq.top().first;
        int currV = pq.top().second;
        pq.pop();
        
        if (currT > dist[currV]) {
            continue;
        }
        
        for (auto& n : graph[currV]) {
            int nextV = n.first;
            int weight = n.second.first;
            int time = n.second.second;

            if (weight > maxW) {
                continue;
            }

            if (dist[nextV] > currT + time) {
                dist[nextV] = currT + time;
                pq.push({dist[nextV], nextV});
            }
        }
    }
    return dist[endV] <= maxTime;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int V, E, batteryLife;
    cin >> V >> E >> batteryLife;
    
    int from, to, kg, time;
    int maxWeight = 0;
    for (int i = 0; i < E; i++) {
        cin >> from >> to >> kg >> time;
        graph[from].push_back({to, {kg, time}});
        maxWeight = max(maxWeight, kg);
    }
    
    vector<int> dist(V+1, INT_MAX);
    int startV = 1, endV = V;
    int maxTime = batteryLife;
    int begin = 1, end = maxWeight;
    
    int result = -1;
    while (begin <= end) {
        int mid = begin + (end - begin) / 2;
        
        if (dijkstra(startV, endV, maxTime, mid)) {
            result = mid;
            end = mid - 1;
        } else {
            begin = mid + 1;
        }
    }
    
    cout << result << endl;
    return 0;
}
