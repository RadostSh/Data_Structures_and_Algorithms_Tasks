class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int curr, int& vertex, int& edge){
        visited[curr] = true;
        edge += graph[curr].size();
        vertex++;

        for(auto& n : graph[curr]) {
            if(!visited[n]) {
                dfs(graph, visited, n, vertex, edge);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>());

        for(auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                int vertex = 0;
                int edge = 0;
                dfs(graph, visited, i, vertex, edge);

                if(vertex * (vertex - 1) == edge) {
                    count++;
                }
            }
        }
        return count;
    }
};