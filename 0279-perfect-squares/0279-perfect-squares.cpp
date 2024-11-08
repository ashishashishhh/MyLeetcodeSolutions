class Solution {
public:
    int helper(int n, int nroot, vector<vector<int>> &dp){
        if(nroot==0)
         return 0;
        if(nroot==1)
         return n;  
        if(dp[n][nroot]!=-1)
         return dp[n][nroot];

        int notPick = 0 + helper(n,nroot-1,dp);
        int pick = 1e9;
        if((nroot*nroot)<=n)
         pick = 1+helper(n-(nroot*nroot),nroot,dp);

        return dp[n][nroot] = min(pick,notPick);
    }
    int numSquares(int n) {
        int nroot= sqrt(n);
        vector<vector<int>>dp(n+1,vector<int>(nroot+1,-1));
        return helper(n,nroot,dp);
    }
};