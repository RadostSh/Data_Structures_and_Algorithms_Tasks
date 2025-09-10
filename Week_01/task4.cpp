#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++){
        int n,m;
        cin >>n>>m;
        
        if(m <= 0){
            cout << "no";
        }
        
        if(m == 1){
            if(n == 0){
                cout << "yes";
            } else {
                cout << "no";
            }
        }
        
        if(m >= 2){
            if((m - n) >= 2){
                cout << "no";
            } else if(abs(m - n) & 1){
                cout << "yes";
            } else {
                cout << "no";
            }
        }
        cout << endl;
    }
    return 0;
}