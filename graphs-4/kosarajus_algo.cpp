
class Solution
{
    private:
    void dfs(int node, vector<int> &vis,vector<vector<int>>& adj, stack<int> &st ){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it])dfs(it, vis, adj, st);
        }
        st.push(node);
    }
    void dfs2(int node, vector<int> &vis2,vector<int> adjt[]){
        vis2[node] = 1;
        for(auto it: adjt[node]){
            if(!vis2[it])dfs2(it, vis2, adjt);
        }
    }
	public:
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> vis(V,0);
        stack<int> st;
        for(int i =0; i<V; i++){
            if(!vis[i])dfs(i, vis, adj, st);
        }
        
        vector<int> adjt[V];
        for(int i = 0; i<V; i++){
            vis[i] =0;
            for(auto it: adj[i]){
                adjt[it].push_back(i);
            }
        }
        int scc = 0;
                vector<int> vis2(V,0);

        while(!st.empty()){
            int node= st.top();
            st.pop();
            if(!vis2[node]){
                scc++;
                dfs2(node, vis2, adjt);
            }
        }
        return scc;
    }
};