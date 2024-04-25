class Solution{
    public:
        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
            vector<pair<int,int>>adj[n+1];    
            for(int i=0;i<edges.size();i++)
            {
                adj[edges[i][0]].push_back({edges[i][1],0});
                adj[edges[i][1]].push_back({edges[i][0],1});
            }
            
            vector<int>dist(n+1,INT_MAX);
            dist[src]=0;
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            pq.push({0,src});
            
            while(!pq.empty())
            {
                int wt=pq.top().first;
                int node=pq.top().second;
                pq.pop();
                
                for(auto it:adj[node])
                {
                    int next=it.first;
                    int next_wt=it.second;
                    if(next_wt+wt<dist[next])
                    {
                        dist[next]=next_wt+wt;
                        pq.push({dist[next],next});
                    }
                }
            }
            if(dist[dst]!=INT_MAX)return dist[dst];
            return -1;
        }
};