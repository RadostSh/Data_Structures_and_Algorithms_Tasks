#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const size_t MAX_SIZE = 1e3;
const size_t MAX_TIME = 1e4 + 80;
const size_t MOD = 1e9 + 7;
size_t dp[MAX_SIZE + 1][MAX_TIME + 1];
size_t arr[MAX_SIZE + 1];

size_t countSums(size_t n)
{
    size_t result = 1;

    for (size_t i = 1; i <= n; i++)
    {
        for (size_t j = 1; j <= MAX_TIME; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (arr[i - 1] <= j)
            {
                dp[i][j] += (dp[i - 1][j - arr[i - 1]]);
                dp[i][j] %= MOD;
            }
        }
    }

    for (size_t j = 1; j <= MAX_TIME; j++)
    {
        result += dp[n][j];
        result %= MOD;
    }

    return result;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    size_t N;
    std::cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        std::cin >> arr[i];
    }

    for (size_t i = 0; i <= N; i++)
    {
        dp[i][0] = 1;
    }

    for (size_t i = 1; i <= MAX_TIME; i++)
    {
        dp[0][i] = 0;
    }

    std::cout << countSums(N);

    return 0;
}
