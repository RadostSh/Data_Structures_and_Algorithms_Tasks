#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long N, Q;
    cin >> N >> Q;
    
    vector<long long> v(N);
    
    for(long long i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    for(long long i = 0; i < Q; i++) {
        long long minEl, maxEl;
        cin >> minEl >> maxEl;
        
        auto beg = lower_bound(v.begin(), v.end(), minEl);
        auto end = upper_bound(v.begin(), v.end(), maxEl);
        
        long long res = 0;
        
        if(minEl > maxEl) {
            res = 0;
        } else {
            res = end - beg;
        }
        
        cout << res << endl;
    }
    
    return 0;
}