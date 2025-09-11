#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Area {
    size_t top = 4000 + 1;
    size_t bottom = 0;
    size_t left = 4000 + 1;
    size_t right = 0;
};

struct Cell {
    size_t componentIndex = 0;
    bool isBurningTree = false;
};

void dfs(size_t x, size_t y, vector<vector<Cell>>& matrix, size_t N, size_t componentIndex, vector<Area>& components) {
    if (x >= N || y >= N || x < 0 || y < 0) {
        return;
    }
    if (matrix[x][y].componentIndex != 0 || !matrix[x][y].isBurningTree) {
        return;
    }

    matrix[x][y].componentIndex = componentIndex;
    components[componentIndex].top = min(components[componentIndex].top, x);
    components[componentIndex].bottom = max(components[componentIndex].bottom, x);
    components[componentIndex].left = min(components[componentIndex].left, y);
    components[componentIndex].right = max(components[componentIndex].right, y);

    dfs(x - 1, y, matrix, N, componentIndex, components);
    dfs(x + 1, y, matrix, N, componentIndex, components);
    dfs(x, y - 1, matrix, N, componentIndex, components);
    dfs(x, y + 1, matrix, N, componentIndex, components);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    size_t N;
    cin >> N;
    
    vector<vector<Cell>> matrix(N, vector<Cell>(N));
    vector<pair<size_t, size_t>> coordinatesOfBurnTree;
    
    for(size_t i = 0; i < N; i++) {
        for(size_t j = 0; j < N; j++) {
            cin >> matrix[i][j].isBurningTree;
            if(matrix[i][j].isBurningTree) {
                coordinatesOfBurnTree.push_back({i, j});
            }
        }
    }
    
    vector<Area> components(1);
    size_t currentComponentIndex = 1;
    
    for(auto& c : coordinatesOfBurnTree) {
        if(matrix[c.first][c.second].componentIndex != 0)
            continue;
        components.push_back(Area());
        dfs(c.first, c.second, matrix, N, currentComponentIndex, components);
        currentComponentIndex++;
    }
    
    priority_queue<size_t> res;
    
    for(size_t i = 1; i < currentComponentIndex; i++) {
        res.push((components[i].bottom - components[i].top + 1) * (components[i].right - components[i].left + 1));
    }
    
    while(!res.empty()) {
        cout << res.top() << " ";
        res.pop();
    }
    
    return 0;
}
