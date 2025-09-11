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
    
    string s1, s2;
    cin >> s1 >> s2;
    
    size_t res = 0;
    size_t currMax = 0;
    for (size_t i = 0; i < s1.size(); i++)
    {
        currMax = 0;
        size_t row = i;
        size_t j = 0;
        while (j < s2.size() && row < s1.size())
        {
            if (s1[row] != s2[j])
            {
                currMax = 0;
            }
            else
            {
                currMax++;
                res = max(res, currMax);
            }
            
            j++;
            row++;
        }
    }

    cout << res;

    return 0;
}