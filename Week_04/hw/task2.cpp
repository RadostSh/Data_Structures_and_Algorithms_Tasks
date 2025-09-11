#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <climits>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, k;
    cin >> N >> k;
    
    deque<long long> d;
    long long minElement = LLONG_MAX;
    
    long long x;
    for (int i = 0; i < k; i++) {
        cin >> x;
        d.push_back(x);
        minElement = std::min(x, minElement);
    }
    
    long long sum = minElement;
    
    for(int i = 0; i < N - k; i++) {
        long long el = d.front();
        d.pop_front();
        
        cin >> x;
        d.push_back(x);
        
        if (x < minElement) {
            minElement = x;
        } else if (el == minElement) {
            minElement = d[0];
            for (int i = 1; i < k; i++)
            {
                minElement = min(d[i], minElement);
            }
        }

        sum += minElement;
        
    }
    
    cout << sum;
    
    return 0;
}