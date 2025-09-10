#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    
    int count = 0;
    
    for(int i = 0; i < str.length(); i++){
        count++;
        if(str[i] == str[i+1]){
            continue;
        }
        
        cout << count << str[i];
        count = 0;
        
    }
    return 0;
}