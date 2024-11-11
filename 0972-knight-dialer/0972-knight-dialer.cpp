class Solution {
public:
    const int mod = 1e9 + 7;
    int dp[5][5][5005];
	// All possible moves knight can make
    int delRow[8] = {-2, -2, -1, +1, +2, +2, +1, -1};
    int delCol[8] = {-1, +1, +2, +2, +1, -1, -2, -2};
    
    int addm(int a, int b) {
        return (a + b) % mod;
    }
    
    int fun(int row, int col, int moves) {
        if (moves == 0)
         return 1;
        
        if (dp[row][col][moves] >= 0)
         return dp[row][col][moves];
        
        int res = 0;
        for (int i = 0; i < 8; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if (nrow >= 0 and nrow < 4 and ncol >= 0 and ncol < 3) {
                if (nrow == 3) {
                    if (ncol == 1) 
                    res = addm(res, fun(nrow, ncol, moves - 1)); 
                }
                else {
                    res = addm(res, fun(nrow, ncol, moves - 1));
                }
            }
        }
        
        return dp[row][col][moves] = res;
    }
    
    int knightDialer(int n) {
        memset(dp, -1, sizeof(dp));
        int res = 0;
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 3; col++) {
                if (row == 3) {
                    if (col == 1)
                     res = addm(res, fun(row, col, n - 1));
                }
                else {
                    res = addm(res, fun(row, col, n - 1));
                }
            }
        }
        return res;
    }
};