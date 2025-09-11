#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, M;
    cin >> N >> M;
    
    vector<int> nums(M);
    unordered_set<int> uniqueNums;
    for (int i = 0; i < M; i++) {
        cin >> nums[i];
        uniqueNums.insert(nums[i]);
    }
    
    vector<int> newNums;
    for(int i = 1; i <= N; i++) {
        if(!(uniqueNums.count(i))) {
            newNums.push_back(i);
        }
    }
    
    vector<int> res;
    int j = 0;
    for(int i = 0; i < N; i++) {
        if(i < M) {
            while(newNums[j] < nums[i] && j < newNums.size()) {
                res.push_back(newNums[j]);
                j++;
            }
            res.push_back(nums[i]);
        } else if(j < newNums.size()){
            res.push_back(newNums[j]);
            j++;
        }
    }
    
    for(int i = 0; i < N; i++) {
        cout << res[i] << " ";
    }
    
    return 0;
}
