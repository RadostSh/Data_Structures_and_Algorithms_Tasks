#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int ternarySearch(long long beg, long long end, long long friendNum, int count) {
    
    if(beg == end) {
        return count;
    }
    
    long long mid1 = beg + (end - beg)/3;
    long long mid2 = mid1 + (end - beg)/3 + 1;
    
    if(mid1 < friendNum && mid2 >= friendNum) {
        return count;
    } else if(friendNum <= mid1 && friendNum >= beg) {
        return ternarySearch(beg, mid1, friendNum, count + 1);
    } else if (friendNum > mid2 && friendNum <= end){
        return ternarySearch(mid2 + 1, end, friendNum, count + 1);
    }
    
    return -1;
}

int main() {
    long long N, P;
    cin >> P >> N;
    vector<long long> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    long long maxCountFriends = pow(3,P);
    
    long long beg = 1;
    long long end = maxCountFriends;
    int count = 1;
    
    for (int i = 0; i < N; i++) {
        long long friendNum = v[i];
        int countOfCandy = ternarySearch(beg, end, friendNum, count);
        cout << countOfCandy << endl;
    }
    
    return 0;
}