#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

bool check(vector<long long>& v, long long N, long long T, long long maxSum){
    long long count = 0;
    long long currSum = 0;
    for (long long i = 0; i < N; i++) {
        if(v[i] > maxSum) {
            return false;
        }
        currSum += v[i];
        
        if(currSum > maxSum) {
            count++;
            currSum = 0;
            i--;
        }
    }
    return count + 1 <= T;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long N, T;
    cin >> N >> T;
    vector<long long> v(N);
    
    for (long long i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    long long beg = 0;
    long long end = LLONG_MAX; 
    
    while(beg <= end) {
        long long mid = beg + (end - beg)/2;
        if(check(v, N, T, mid)) {
            end = mid - 1;
        } else {
            beg = mid + 1;
        }
    }
    
    cout << beg;
    
    
    return 0;
}