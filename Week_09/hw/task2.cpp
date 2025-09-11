#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> graph(1e6);
vector<ll> myFriendGroup;
vector<ll> friendsGroups(1e6);
vector<bool> visited(1e6, false);

ll bfs(ll start, ll targetGroup) {
    queue<ll> q;
    q.push(start);
    visited[start] = true;
    ll dist = 0;
    
    while(!q.empty()) {
        ll levelSize = q.size();
        for(ll i = 0; i < levelSize; i++) {
            ll curr = q.front();
            q.pop();
            
            if(friendsGroups[curr - 1] == targetGroup && curr != start){
                return dist;
            }
            
            for(auto& n: graph[curr]) {
                if(!visited[n]){
                    visited[n] = true;
                    q.push(n);
                }
            }
        } 
        dist++;
    }
    return LLONG_MAX;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    ll v, e;
    cin >> v >> e;
    
    int x, y;
    for(ll i= 0; i < e; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    for(ll i = 0; i < v; i++) {
        cin >> friendsGroups[i];
    }
    
    cin >> y;
    for(ll i = 0; i < v; i++) {
        if(friendsGroups[i] == y) {
            myFriendGroup.push_back(i+1);
        }
    }
    
    ll minDist = LLONG_MAX;
    for(auto& fr : myFriendGroup) {
        ll dist = bfs(fr, y);
        minDist = min(minDist, dist);
    }
    
    cout << ((minDist == LLONG_MAX) ? -1 : minDist);
    
    return 0;
}
