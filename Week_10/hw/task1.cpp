#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int V, E, start, end;
    cin >> V >> E >> start >> end;
    
    vector<int> times(V);
    for(int i = 0 ; i < V; i++) {
        cin >> times[i];
    }
    
    vector<vector<pair<long long, int>>> graph(V+1, vector<pair<long long, int>>());
    
    for(int i = 0; i < E; i++) {
        int v, t, w;
        cin >> v >> t >> w;
        graph[v].push_back({t, w});
    }
    
    vector<long long> dist(V+1, LLONG_MAX);
    dist[start] = 0;
    
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, start});
    
    while(!pq.empty()) {
        long long curr_dist = pq.top().first;
        int curr_v = pq.top().second;
        pq.pop();
        
        if(curr_v == end) {
            cout << dist[curr_v];
            break;
        }
        
        for(auto& p : graph[curr_v]) {
            long long v = p.first;
            int w = p.second;
            long long needTimeWait = curr_dist % times[curr_v];
            long long newTime = curr_dist + w;
            
            if(needTimeWait != 0) {
                newTime += (times[curr_v] - needTimeWait);
            }
            
            if(dist[v] > newTime) {
                dist[v] = newTime;
                pq.push({newTime, v});
            }
        }
    }
    
    if(dist[end] == LLONG_MAX) {
        cout << -1;
    }
    
    return 0;
}
