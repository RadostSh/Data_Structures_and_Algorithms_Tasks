#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> h(n);
    
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    
    long long maxArea = 0;
    int beg = 0;
    int end = h.size() - 1;
    
    while(beg != end){
        long long currArea = min(h[beg], h[end]) * (end - beg);
        maxArea = max(maxArea, currArea);
        
        if(h[beg] < h[end]){
            beg++;
        } else{
            end--;
        }
    }
    
    cout << maxArea;
    
    return 0;
}