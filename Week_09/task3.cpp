#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, S;
    cin >> N >> S;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int P;
    for(int i = 0; i < N; i++) {
        cin >> P;
        pq.push(P);
    }
    
    int days = 0;
    while(!pq.empty()) {
        int s1 = pq.top();
        pq.pop();
        
        if(s1 >= S) {
            cout << days;
            break;
        }
        
        if(!pq.empty()) {
            int s2 = pq.top();
            pq.pop();

            int s3 = s1 + 2 * s2;
            pq.push(s3);

            days++;
        }
    }
    
    if(pq.empty()) {
        cout << -1;
    }
    
    return 0;
}