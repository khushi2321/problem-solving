class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<pair<int,int> > > adj(n);
        int ans =INT_MAX;
        int mn=INT_MAX;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        for(int i=0;i<n;i++){
            queue<int> q;
            q.push(i);
            vector<int> dis(n,INT_MAX);
            dis[i]=0;
            while(!q.empty()){
                int front = q.front();
                q.pop();
                int d=dis[front];

                for(auto &it: adj[front]){
                    int node = it.first;
                    int ds = it.second;
                    if(d+ds<=dis[node]){
                        dis[node]=d+ds;
                        q.push(node);
                    }
                }
            }
            int cnt =0;
            for(int k=0;k<dis.size();k++){
                if(dis[k]<=dt) cnt++;
            }
                if(cnt<=mn){
                    mn=cnt;
                    ans=i;
                }
        }
        return ans;   
    }
};