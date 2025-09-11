#include <bits/stdc++.h>
using namespace std;

struct Edge{
    long long from, to, c1, c2, index;
    
    bool operator<(const Edge& other) const {
        if(c1 == other.c1) {
           return c2 > other.c2;
        }
        return c1 < other.c1;
    }
};

struct DJS{
    vector<long long> parents;
    vector<long long> size;
    
    DJS(long long n) : size(n+1, 1) {
        for(int i = 0; i <= n; i++) {
            parents.push_back(i);
        }
    }
    
    long long find(long long v) {
        if(v == parents[v]) {
            return v;
        }
        return parents[v] = find(parents[v]);
    }
    
    bool unite(long long v, long long u) {
        long long pV = find(v);
        long long pU = find(u);
        
        if(pV == pU) {
            return false;
        }
        
        if(size[pU] > size[pV]) {
            swap(pU, pV);
        }
        
        parents[pU] = pV;
        size[pV] += size[pU];
        return true;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    long long V, E;
    cin >> V >> E;
    
    vector<Edge> edges(E);
    
    for(int i = 0; i < E; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].c1 >> edges[i].c2;
        edges[i].index = i + 1; 
    }
    
    sort(edges.begin(), edges.end());
    DJS djs(V);
    long long count = 0;
    
    for(auto& edge : edges) {
        if(djs.unite(edge.from, edge.to)) {
            count++;
            cout << edge.index << endl;
        }
        
        if(count == V - 1) {
            break;
        }
    }
    
    return 0;
}