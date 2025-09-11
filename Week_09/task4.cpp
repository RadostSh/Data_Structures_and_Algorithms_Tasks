#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> all;
priority_queue<int, vector<int>, greater<int>> waiting;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int N;
    cin >> N;
    
    int start;
    int end;
    for(int i = 0; i < N; i++) {
        cin >> start >> end;
        all.push(make_pair(start, end));
    }
    
    int time = 0;
    size_t maxCount = 0;
    
    while(!all.empty()) {
        while(!all.empty() && all.top().first <= time) {
            auto interval = all.top();
            all.pop();
            waiting.push(interval.second);
        }
        
        while(!waiting.empty() && waiting.top() <= time) {
            waiting.pop();
        }
        
        maxCount = max(maxCount, waiting.size());
        time = all.top().first;
    }
    
    cout << maxCount;
    
    return 0;
}
