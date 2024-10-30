class Solution {
public:
    int solveTopDown(vector<vector<char>>& matrix, int i, int j, int &n, int &m, vector<vector<int>>& dp) {
        // Base case: If out of bounds, return 0
        if (i >= n || j >= m) return 0;
        
        // Check if this subproblem has already been solved
        if (dp[i][j] != -1) return dp[i][j];
        
        // Recursive case: Calculate right, diagonal, and down squares
        int right = solveTopDown(matrix, i, j + 1, n, m, dp);
        int diagonal = solveTopDown(matrix, i + 1, j + 1, n, m, dp);
        int down = solveTopDown(matrix, i + 1, j, n, m, dp);
        
        // If current cell is '1', compute the side length of the square
        if (matrix[i][j] == '1') 
            return dp[i][j] = 1 + min({right, diagonal, down});
        else 
            return dp[i][j] = 0;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi = 0;
        
        // DP table initialized with -1 to signify uncomputed subproblems
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        // Calculate the largest square ending at each cell in the matrix
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '1') {
                    maxi = max(maxi, solveTopDown(matrix, i, j, n, m, dp));
                }
            }
        }
        
        // Return the area of the largest square
        return maxi * maxi;
    }
};
