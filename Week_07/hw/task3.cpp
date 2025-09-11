#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        unordered_map<int, int> boxes;
        int X, N;
        cin >> X >> N;
        
        vector<int> v(N);
        for(int j = 0; j < N; j++) {
            cin >> v[j];
            
            if(boxes.count(X - v[j])) {
                cout << boxes[X - v[j]] << " " << j + 1;
            }
            boxes[v[j]] = j + 1;
        }
        cout << endl;
    }
    return 0;
}