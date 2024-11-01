class Solution {
public:
    int fun(vector<vector<int>>& obstacleGrid,int n,int m,int i,int j,vector<vector<int>>&dp){
        if(i>=n|| j>=m || obstacleGrid[i][j]==1)
        return 0;

        if(i==n-1 && j==m-1)
        return 1;

        if(dp[i][j]!=-1)
        return dp[i][j];

        return dp[i][j] = fun(obstacleGrid,n,m,i+1,j,dp) + fun(obstacleGrid,n,m,i,j+1,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n= obstacleGrid.size();
        int m= obstacleGrid[0].size();
        vector<vector<int>>dp(n ,vector<int>(m ,-1));
        return fun(obstacleGrid,n,m,0,0,dp);
        
    }
};