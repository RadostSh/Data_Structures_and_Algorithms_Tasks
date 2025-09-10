#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int k;

    cin >> n;
    cin >> k;
    
    vector<int> nums(n);
    
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == k){
            nums.erase(nums.begin() + i);
            i--;
        }
    }
    
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    
}