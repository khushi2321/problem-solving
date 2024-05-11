class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
         return 0;
        if(n<2) 
        return nums[0];
        int dp1[n+1];
        int dp2[n+1];
        dp1[0] = 0;
        dp1[1] = nums[0];
        dp2[0] = 0;
        dp2[1] = 0;
        for(int i = 2; i <= n; i++) {
            dp1[i] = max(dp1[i-1], nums[i-1] + dp1[i-2]);
            dp2[i] = max(dp2[i-1], nums[i-1] + dp2[i-2]);
        }
        return max(dp1[n-1], dp2[n]);
    }
};