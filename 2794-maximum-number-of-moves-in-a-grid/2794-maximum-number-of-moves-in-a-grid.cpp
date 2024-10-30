class Solution {
public:
    int fun(vector<vector<int>>& grid,int row,int col,int i,int j,vector<vector<int>>&dp){

        if(i>=row || j>=col)
        return 0;

        if(j==col-1)
        return 0;

        if(dp[i][j]!=-1)
        return dp[i][j];

        int first = 0 , second = 0 , third = 0;
        if(i-1>=0 && j+1<col && grid[i-1][j+1]>grid[i][j]){
            first = 1 + fun(grid,row,col,i-1,j+1,dp);
        }
        if(j+1<col && grid[i][j+1]>grid[i][j]){
            second = 1 + fun(grid,row,col,i,j+1,dp);
        }

        if(j+1<col && i+1<row && grid[i+1][j+1]>grid[i][j]){
            third = 1 + fun(grid,row,col,i+1,j+1,dp);
        }
 
        return dp[i][j] = max(first , max(second,third));
    }
    int maxMoves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int ans = 0;

        vector<vector<int>>dp(row,vector<int>(col,-1));
        for(int i=0;i<row;i++)
            ans = max(ans,fun(grid,row,col,i,0,dp));
        

        return ans;
    }
};