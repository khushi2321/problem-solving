class Solution {
public: 
    void dfs(vector<vector<int>> &graph, vector<vector<int>> &res, vector<bool> &vis, int start, int store) {
        vis[start] = true;
        for (int node : graph[start]) {
            if (!vis[node]) {
                res[node].push_back(store);
                dfs(graph, res, vis, node, store);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto &i : edges) {
            graph[i[0]].push_back(i[1]);
        }
        vector<vector<int>> res(n);
        for (int i = 0; i < n; ++i) {
            vector<bool> visited(n);
            visited[i] = true;
            dfs(graph, res, visited, i, i);
        }
        return res;
    }
};