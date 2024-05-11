class Solution {
public:
//recursion
   /* int helper(int i, int n){
        if(n==0) return 0;

        if(i*i <= n){
            return min(1+helper(i, n-i*i), helper(i+1, n));
        }
        return 1e5;
    }
    int numSquares(int n) {
        return helper(1, n);
    }
};
//memoization
 int helper(int i, int n, vector<int>&dp){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        if(i*i <= n){
            return dp[n]=min(1+helper(i, n-i*i, dp), helper(i+1, n, dp));
        }
        return dp[n]=1e5;
    }
    int numSquares(int n) {
        vector<int>dp(n+1, -1);
        return helper(1, n, dp);
    }
};*/
//dp
    int numSquares(int n) {
        vector<int>dp(n+1, 1e5);
        dp[0]=0;
        int j=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                dp[i]=min(1+dp[i-j*j], dp[i]);
            }
        }
        return dp[n];
    }
};

