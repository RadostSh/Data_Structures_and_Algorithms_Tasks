#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const size_t MOD = 1e9 + 7;

size_t plantFlowers(size_t n) {
    if(n == 1 || n == 2) {
        return 2;
    }
    
    size_t curr1 = 2;
    size_t curr2 = 2;
    
    for(size_t i = 3; i < n + 1; i++) {
        size_t temp = curr2;
        curr2 += curr1;
        curr1 = temp;
        curr2 %= MOD;
        curr1 %= MOD;
    }
    
    return curr2;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    size_t n;
    std::cin >> n;
    
    size_t result = plantFlowers(n);
    
    std::cout << result;
    return 0;
}
