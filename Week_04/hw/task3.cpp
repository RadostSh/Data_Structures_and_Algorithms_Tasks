#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int N;
    cin >> N;
    
    queue<int> allElements;
    deque<int> positiveElemnts;
    
    int el;
    for(int i = 0; i < N; i++) {
        cin >> el;
        allElements.push(el);
    }
    
    while(!allElements.empty()) {
        int currEl = allElements.front();
        
        if(currEl < 0 && positiveElemnts.empty()) {
            cout << currEl << " ";
            allElements.pop();
        } else if(currEl < 0 && !positiveElemnts.empty()) {
           int possEl = positiveElemnts.back();
            
            if(abs(currEl) > possEl) {
                positiveElemnts.pop_back();
            } else if(abs(currEl) < possEl) {
                allElements.pop();
            } else {
                positiveElemnts.pop_back();
                allElements.pop();
            }
        } else {
            positiveElemnts.push_back(currEl);
            allElements.pop();
        } 
    }
    
    while(!positiveElemnts.empty()) {
        cout << positiveElemnts.front() << " ";
        positiveElemnts.pop_front();
    }
    
    return 0;
}