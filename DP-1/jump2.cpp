class Solution {
public:
//recursion
    /*int n;
    int solve(int i, vector<int> &nums)
    {
        if(i == n-1)  
            return 0;
        int mini = INT_MAX-1;                      
        for(int j=1; j<=min(n-1 - i, nums[i]); j++) 
        {
            int temp = 1 + solve(i+j, nums); 
            mini = min(mini, temp);         
        }  
        return mini;  
    }  
    int jump(vector<int>& nums) 
    {
        n = nums.size(); 
        return solve(0, nums, dp);
    }
};
//memoization
    int n;
    int solve(int i, vector<int> &nums, vector<int> &dp)
    {
        if(i == n-1)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int mini = INT_MAX-1;
        for(int j=1; j<=min(n-1 - i, nums[i]); j++)  
        {
            int temp = 1 + solve(i+j, nums, dp);
            mini = min(mini, temp);
        }
        return dp[i] = mini;  
    }
    
    int jump(vector<int>& nums) 
    {
        n = nums.size();
        vector<int> dp(n-1, -1);
        
        return solve(0, nums, dp);
    }
};*/
//dp
	int jump(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n, 0); 
        for(int i=n-2; i>=0; i--)
        {
            int mini = INT_MAX-1;
            for(int j=1; j<=min(n-1 - i, nums[i]); j++) 
            {
                int temp = 1 + dp[i+j];
                mini = min(mini, temp);
            }

            dp[i] = mini;  
        }
        
        return dp[0];
    }
};