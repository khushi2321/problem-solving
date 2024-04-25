class Solution {
public:
    bool dfs(int i ,vector<int>&vis,vector<int>&stk,vector<int> adj[]){
        vis[i]=1;
        stk[i]=1;
        for(auto it  : adj[i]){
            if(!vis[it]){
                if(dfs(it , vis , stk , adj)) return true ;
            }
            else if(vis[it]  && stk[it]){
                return true ;
            }
        }
        stk[i]=0;
        return false ;
    }
    bool canFinish(int numCourses, vector<vector<int>>& pq) {
        int n = numCourses;   
        vector<int> adj[n];
        for(auto x : pq){
            vector<int> data = x;
            int a =data[0];
            int b = data[1];
            adj[a].push_back(b);
            
        }
        vector<int> vis(n,0);
        vector<int> crvisit(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,vis,crvisit ,adj))
                return false ;
            }
        }
        return true ;
    }
};