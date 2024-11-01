class Solution {
public:
    int fun(int n,int m,int i,int j,vector<vector<int>>&dp){
        if(i>=n|| j>=m)
        return 0;

        if(i==n-1 && j==m-1)
        return 1;

        if(dp[i][j]!=-1)
        return dp[i][j];

        return dp[i][j] = fun(n,m,i+1,j,dp) + fun(n,m,i,j+1,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m ,vector<int>(n ,-1));
        return fun(m,n,0,0,dp);
        
    }
};