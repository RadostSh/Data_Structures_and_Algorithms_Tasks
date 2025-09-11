#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int N, M, T;
    cin >> N >> M >> T;
    
    bool arr[1000][1000]{};
    queue<pair<int,int>> rottenApples;
    
    int x, y;
    int count = 0;
    
    while(cin >> x >> y) {
        if(x >= 1 && x <= N && y >= 1 && y <= M) {
          rottenApples.push({x, y});
        }
    }
    
    for(int i = 0; i <= T; i++) {
        int applesToCheck = rottenApples.size();
        for(int j = 0; j < applesToCheck; j++) {
            pair<int,int> currRot = rottenApples.front();
            rottenApples.pop();
            
            if (currRot.first < 1 || currRot.first > N || currRot.second < 1 || currRot.second > M)
            {
                continue;
            }
            
            if(arr[currRot.first][currRot.second]) {
                continue;
            }
            
            arr[currRot.first][currRot.second] = true;
            ++count;
            
            rottenApples.push({currRot.first + 1, currRot.second});
            rottenApples.push({currRot.first, currRot.second + 1});
            rottenApples.push({currRot.first - 1, currRot.second});
            rottenApples.push({currRot.first, currRot.second - 1});
            
        }
    }
    
    cout << N * M - count;
    return 0;
}