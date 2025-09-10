#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; 
    cin >> n;
    
    vector<pair<int, string>> student(n);
    
    for(int i = 0; i < n; i++) {
        cin >> student[i].second;
    }
    
    for(int i = 0; i < n; i++) {
        cin >> student[i].first;
    }
    
    sort(student.begin(), student.end(), [](const pair<int,string>& a, const pair<int,string>& b) {
        if(a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    });
    
    for (int i = 0; i < n; i++) {
        cout << student[i].second << " " << student[i].first << endl;
    }
    
    return 0;
}