#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<char>> graph('z' + 1);
vector<bool> charInThisAlphabet('z' + 1, false);
vector<bool> visitedChar('z' + 1, false);
vector<char> res;

void dfs(char curr) {
    
    visitedChar[curr] = true;
    
    for(auto& n : graph[curr]) {
        if(!visitedChar[n]){
            dfs(n);
        }
    }
    
    res.push_back(curr);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    size_t N;
    cin >> N;
    
    vector<string> words(N);
    for(size_t i = 0; i < N; i++) {
        cin >> words[i];
    }
    
    for(size_t i = 0; i < N - 1; i++) {
        for(size_t j = 0; j < min(words[i].size(), words[i+1].size()); j++) {
            if(words[i][j] == words[i + 1][j]) {
                continue;
            }
            
            graph[words[i][j]].push_back(words[i + 1][j]);
            charInThisAlphabet[words[i][j]] = true;
            charInThisAlphabet[words[i + 1][j]] = true;
            break;
        }
    }
    
    for (char i = 'a'; i <= 'z'; i++) {
        if (!charInThisAlphabet[i]) {
            continue;
        }
        
        if(!visitedChar[i]){
            dfs(i);
        }
    }
    
    for(int i = res.size() - 1; i >= 0; i--) {
        cout << res[i] << " ";
    }
    
    return 0;
}
