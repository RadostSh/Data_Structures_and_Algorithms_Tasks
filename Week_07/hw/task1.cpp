#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, B;
    cin >> N >> B;
    
    vector<int> v(N);
    int indexOfMed = 0;
    
    for(int i = 0; i < N; i++) {
        cin >> v[i];
        if(v[i] == B) {
            indexOfMed = i;
        }
    }
    
    int res = 0;
    map<int, int> balance;
    
    int count = 0;
    for(int i = indexOfMed; i >= 0; i--) {
        if (v[i] < B)
            count--;
        else if (v[i] > B)
            count++;
        balance[count]++;
    }
    
    count = 0;
    for (long long i = indexOfMed; i < N; i++)
    {
        if (v[i] < B)
            count--;
        else if (v[i] > B)
            count++;
        res += balance[-count];
    }

    cout << res;
    
    return 0;
}
