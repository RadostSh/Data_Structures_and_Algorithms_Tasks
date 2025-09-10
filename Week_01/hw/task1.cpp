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
    
    string str;
    cin >> str;
    
    int count[62]{0};
    
    for(size_t i = 0; i < str.size(); i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            count[str[i] - '0']++;
        } else if(str[i] >= 'a' && str[i] <= 'z') {
            count[str[i] - 'a' + 10]++;
        } else if(str[i] >= 'A' && str[i] <= 'Z') {
            count[str[i] - 'A' + 36]++;
        }
    }
    
    string result;
    
    for (int i = 0; i < 62; i++) {
        if(i < 10) {
            result += string(count[i], char(i + '0'));
        } else if (i < 36) {
            result += string(count[i], char(i - 10 + 'a'));
        } else {
            result += string(count[i], char(i - 36 + 'A'));
        }
    }
    
    cout << result;
    
    return 0;
}