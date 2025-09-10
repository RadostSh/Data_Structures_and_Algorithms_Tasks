#include <bits/stdc++.h>
using namespace std;


int main() {
    int minGrade, count;
    cin >> minGrade >> count;
    vector<int> grades(count);
    
    for(int i = 0; i < count; i++){
        cin >> grades[i];
    }
    
    long long n = 0;
    
    for(int i = 0; i < grades.size(); i++){
        if(grades[i] > minGrade){
            n += abs(grades[i] - minGrade);
        } else if(grades[i] < minGrade){
            n -= abs(minGrade - grades[i]);
        }
    }
    
    if(n >= 0){
        cout << "yes";
    } else {
        cout << "no";
    }
    
    return 0;
}