class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool>vertices(n,true);
        for(int i=0;i<edges.size();i++){
            vertices[edges[i][1]]=false;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(vertices[i]==true){
                ans.push_back(i);
            }
        }
        return ans;
    }
};