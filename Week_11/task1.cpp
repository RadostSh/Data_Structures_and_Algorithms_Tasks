#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

constexpr long long MODULE = 1e9 + 7;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int V, E;
    cin >> V >> E;
    
    vector<vector<pll>> graph(V+1, vector<pll>());
    
    int f, t, w;
    for(int i = 0; i < E; i++) {
        cin >> f >> t >> w;
        graph[f].push_back({t, w});
    }
    
    vector<ll> dist(V+1, LLONG_MAX);
    vector<ll> count(V+1, 0);
    
    ll start = 1;
    ll end = V;
    
    dist[start] = 0;
    count[start] = 1;
    
    priority_queue<pll, vector<pll>, greater<>> pq;
    pq.push({0, start});
    
    while(!pq.empty()) {
        ll curr_V = pq.top().second;
        ll curr_dist = pq.top().first;
        pq.pop();
        
        if(curr_dist > dist[curr_V]) {
            continue;
        }
        
        for(auto& n : graph[curr_V]) {
            ll v = n.first;
            ll w = n.second;
            ll newW = dist[curr_V] + w;
            if(newW < dist[v]) {
                dist[v] = newW;
                pq.push({dist[v], v});
                count[v] = count[curr_V];
            }else if(newW == dist[v]) {
                count[v] = (count[v] + count[curr_V]) % MODULE;
            }
        }
    }
    
    if(dist[end] != LLONG_MAX) {
        cout << dist[end] << " " << count[end];
    } else {
        cout << "-1 0";
    }
    
    return 0;
}
