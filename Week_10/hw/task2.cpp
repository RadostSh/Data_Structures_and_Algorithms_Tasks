#include <bits/stdc++.h>
using namespace std;

bool canMove(int x, int y, int R, int C) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int R, C;
    cin >> R >> C;

    vector<vector<int>> graph(R, vector<int>(C));
    vector<vector<int>> dist(R, vector<int>(C, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    char ch;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> ch;
            graph[i][j] = (ch == '#' ? 1 : 0);
            if (i == 0 || i == R - 1 || j == 0 || j == C - 1) {
                dist[i][j] = graph[i][j];
                pq.push({ graph[i][j], {i, j} });
            }
        }
    }

    while (!pq.empty()) {
        int cost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (cost > dist[x][y]) {
            continue;
        }

        int dx[] = { -1, 1, 0, 0 };
        int dy[] = { 0, 0, -1, 1 };

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i]; 
            int newY = y + dy[i];
            if (canMove(newX, newY, R, C) && dist[newX][newY] > cost + graph[newX][newY]) {
                dist[newX][newY] = cost + graph[newX][newY];
                pq.push({ dist[newX][newY], {newX, newY} });
            }
        }
    }

    int maxDist = 0;
    for (int i = 1; i < R - 1; i++)
    {
        for (int j = 1; j < C - 1; j++)
        {
            if (graph[i][j] == 0 && dist[i][j] > maxDist)
            {
                maxDist = dist[i][j];
            }
        }
    }

    int count = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            count += (!graph[i][j] && dist[i][j] == maxDist);
        }
    }

    cout << count;

    return 0;
}
