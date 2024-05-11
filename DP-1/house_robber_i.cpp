class Solution {
public:/*tabulation
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        vector<int> dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);        
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[n-1];
    }
};*/
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int prev1 = 0;
        int prev2 = 0;
        for (int i=0;i<nums.size();++i) 
        {
            int temp = prev1;
            prev1 = max(prev2 + nums[i], prev1);
            prev2 = temp;
        }
        return prev1;
    }
};