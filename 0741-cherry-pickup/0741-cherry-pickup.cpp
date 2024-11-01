class Solution {
public:
     int cherryHelperFunc(vector<vector<int>>&grid, int r1, int c1, int c2, vector<vector<vector<int>>>&dp){
        int n = grid.size();
        int r2 = r1 + c1 - c2;
        if(r1 == n || r2 == n || c1 == n || c2 == n)
            return INT_MIN;
        
        if(grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;
        
        if(dp[r1][c1][c2] != -1){
            return dp[r1][c1][c2];
        }
        
        if(r1 == n-1 && c1 == n-1)
            return grid[n-1][n-1];
        
        int answer = grid[r1][c1];
        if(r1 != r2)
            answer += grid[r2][c2];
        
        // down down, right right, down right, right down
        int temp = max( {cherryHelperFunc(grid, r1+1, c1, c2,   dp),
                         cherryHelperFunc(grid, r1+1, c1, c2+1, dp),
                         cherryHelperFunc(grid, r1, c1+1, c2+1, dp),
                         cherryHelperFunc(grid, r1, c1+1, c2, dp)}
                      );
        answer += temp;
        dp[r1][c1][c2] = answer;
        return answer;
        
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return max(0, cherryHelperFunc(grid, 0, 0, 0, dp));
    }
};