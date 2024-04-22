class Solution {
  public:
    bool check_cycle_dfs(int src,vector<bool> &visited,vector<bool> &dfs_call,vector<int> adj[]){
     visited[src]=true;
     dfs_call[src]=true;
     for(auto nbr:adj[src]){
         if(!visited[nbr]){
            bool rec_ans=check_cycle_dfs(nbr,visited,dfs_call,adj);
            if(rec_ans==true){
                return true;
              }
         }
         else if(visited[nbr] && dfs_call[nbr]){
             return true;
         }
     }
     dfs_call[src]=false;  
     return false;   
        
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        vector<bool> dfs_call(V,false);
        bool ans=false;
        for(int i=0; i<V; i++){
          if(!visited[i]){
            ans=check_cycle_dfs(i,visited,dfs_call,adj);
            if(ans==true){
                break;
               }
          }
        }
        return ans;
    }
};