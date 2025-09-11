#include <bits/stdc++.h>
using namespace std;

struct DJS{
    vector<int> parents;
    vector<int> size;
    
    DJS(int n) : size(n+1, 1) {
        for(int i = 0; i <= n; i++) {
            parents.push_back(i);
        }
    }
    
    int find(int v) {
        if(v == parents[v]) {
            return v;
        }
        return parents[v] = find(parents[v]);
    }
    
    void unite(int v, int u) {
        int pV = find(v);
        int pU = find(u);
        
        if(pV == pU) {
            return;
        }
        
        if(size[pU] > size[pV]) {
            swap(pU, pV);
        }
        
        parents[pU] = pV;
        size[pV] += size[pU];
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int V, E;
    cin >> V >> E;
    
    DJS djs(V);
    int x, y;
    for(int i = 0; i < E; i++) {
        cin >> x >> y;
        djs.unite(x, y);
    }
    
    string res = "";
    int Q;
    cin >> Q;
    int request;
    for(int i = 0; i < Q; i++) {
        cin >> request >> x >> y;
        if(request == 1) {
            res += (djs.find(x) == djs.find(y)) ? "1" : "0";
        } else if(request == 2) {
            djs.unite(x, y);
        }
    }
    
    cout << res;
    
    return 0;
}
