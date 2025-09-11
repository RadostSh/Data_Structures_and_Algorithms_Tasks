#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int COUNTER_SIZE = 26;
const int MAX_SPLITS = 3000;
int dp[MAX_SPLITS + 1]{};

bool isEven(const int* arr) {
    for (size_t i = 0; i < COUNTER_SIZE; i++) {
        if (arr[i] != 0 && !(arr[i] & 1)) {
            return true;
        }
    }
    return false;
}

void initDP(size_t size) {
    dp[0] = 0;
    dp[1] = 1;

    for (size_t i = 2; i < size + 1; i++) {
        dp[i] = MAX_SPLITS;
    }
}

void fillDP(string& str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (dp[i] == MAX_SPLITS) {
            continue;
        }

        int counter[COUNTER_SIZE + 1]{};

        for (size_t j = i; j < str.size(); j++) {
            counter[str[j] - 'a']++;

            if (!isEven(counter)) {
                dp[j + 1] = min(dp[i] + 1, dp[j + 1]);
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string S;
    cin >> S;

    initDP(S.size());
    fillDP(S);
    cout << dp[S.size()];
    return 0;
}
