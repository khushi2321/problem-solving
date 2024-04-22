class Solution 
{
    public:
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	   int n=grid.size();
	   int m=grid[0].size();
	   vector<vector<int>> vis(n, vector<int>(m, 0)); 
	    vector<vector<int>> ans(n, vector<int>(m, 0));
	   queue<pair<pair<int,int>,int>> q;
	   for(int i=0;i<n;i++){
	       for(int j=0;j<m;j++){
	           if(grid[i][j] == 1) {
	                q.push({{i,j}, 0}); 
	                vis[i][j] = 1; 
	            }
	       }
	   }
	   int delRow[]={-1,1,0,0};
	   int delCol[]={0,0,-1,1};
	   
	   while(!q.empty()){
	       int i=q.front().first.first;
	       int j=q.front().first.second;
	       int dist=q.front().second;
	       q.pop();
	       
	       for(int k=0;k<4;k++){
	           int newRow=i+delRow[k];
	           int newCol=j+delCol[k];
	           if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && !vis[newRow][newCol]){
	               vis[newRow][newCol]=1;
	               ans[newRow][newCol]=dist+1;
	               q.push({{newRow,newCol},dist+1});
	           }
	       }
	       
	   }
	   return ans;
	}
};