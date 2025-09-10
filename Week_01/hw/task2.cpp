#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void insertedNum(vector<int>& vec, int value) {
    auto it = lower_bound(vec.begin(), vec.end(), value);
    vec.insert(it, value);
}

int main() {  
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> left;
    vector<int> right;
    
    double median = 0.0;
    
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        
        if(left.empty() || num <= left.back()) {
            insertedNum(left, num);
        } else {
            insertedNum(right, num);
        }
        
        if(left.size() > right.size() + 1) {
            right.insert(right.begin(), left.back());
            left.pop_back();
        } else if(right.size() > left.size() + 1) {
            left.push_back(right.front());
            right.erase(right.begin());
        }
        
        if(left.size() > right.size()) {
            median = left.back();
        } else if(right.size() > left.size()) {
            median = right.front();
        } else {
            median = (left.back() + right.front()) / 2.0;
        }
        
        cout << median << endl;
    }
    
    return 0;
}