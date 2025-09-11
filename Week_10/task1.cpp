class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        for(auto& edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> res;
        vector<bool> visited(numCourses, false);
        vector<bool> pathVisited(numCourses, false);

        for(int i = 0; i < numCourses; i++) {
            if(!visited[i] && hasCycle(graph, res, visited, pathVisited, i)) {
                return {};
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }

private:
    bool hasCycle(vector<vector<int>>& graph, vector<int>& res, vector<bool>& visited, vector<bool>& pathVisited, int curr) {
        if(pathVisited[curr]) {
            return true;
        }

        if(visited[curr]) {
            return false;
        }

        visited[curr] = true;
        pathVisited[curr] = true;

        for(int& n : graph[curr]) {
            if(hasCycle(graph, res, visited, pathVisited, n)) {
                return true;
            }
        }

        pathVisited[curr] = false;
        res.push_back(curr);
        return false;
    }
};