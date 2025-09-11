#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    cout << fixed << setprecision(1);
    int N;
    cin >> N;
    
    priority_queue<double> maxHeap;
    priority_queue<double , vector<double>, greater<double>> minHeap;
    
    double x;
    
    for(int i = 0; i < N; i++) {
        cin >> x;

        if(!maxHeap.empty() && maxHeap.top() < x) {
            minHeap.push(x);
        } else {
            maxHeap.push(x);
        }
        
        if(maxHeap.size() > minHeap.size() + 1) {
            int curr = maxHeap.top();
            maxHeap.pop();
            minHeap.push(curr);
        } else if(maxHeap.size() + 1 < minHeap.size()) {
            int curr = minHeap.top();
            minHeap.pop();
            maxHeap.push(curr);
        }
        
        if(maxHeap.size() == minHeap.size()) {
            cout << ((maxHeap.top() + minHeap.top()) / 2.0) << endl;
        } else {
            cout << ((maxHeap.size() > minHeap.size()) ? maxHeap.top() : minHeap.top()) << endl;
        }
        
    }
    
    
    
    return 0;
}
