#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
using ll = long long;

bool check(vector<ll>& v, ll ans, ll target) {
    ll res = 0;
    
    for(ll x : v) {
        res += (ans / x);
    }
    
    return res >= target;
}

int main() { 
    ll n, k;
    cin >> n >> k;
    
    vector<ll> v(k);
    
    ll maxTime = LLONG_MIN;
    ll minTime = LLONG_MAX;
    
    for(int i = 0; i < k; i++) {
        cin >> v[i];
        
        maxTime = max(maxTime, v[i]);
        minTime = min(minTime, v[i]);
    }
    
    ll beg = (n / k) * minTime;
    ll end = (n / k + 1) * maxTime;
    
    ll res = end;
    
    while(beg <= end) {
        ll mid = beg + (end - beg) / 2;
        
        if(check(v, mid, n)) {
            res = min(res, mid);
            end = mid - 1;
        } else {
            beg = mid + 1;
        }
    }
    
    cout << res;
    
    return 0;
}