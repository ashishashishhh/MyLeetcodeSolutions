class Solution {
public:
    int fun(vector<vector<int>>& triangle,int i,int j,int row,int col,vector<vector<int>>&dp){
        if(i<0 || j<0)
        return 0;
    
        if(i>=row || j>=col)
        return 0;
        
        if(i==row-1 && j==col-1)
        return dp[i][j] = triangle[i][j];

        if(dp[i][j]!=INT_MIN)
        return dp[i][j];

        return dp[i][j] = triangle[i][j] + min(fun(triangle,i+1,j+1,row,col,dp),fun(triangle,i+1,j,row,col,dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp;
        dp.resize(n,vector<int>(n,INT_MIN));
        return fun(triangle,0,0,n,n,dp);
    }
};