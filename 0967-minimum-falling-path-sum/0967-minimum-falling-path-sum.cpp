// //TLE
// class Solution {
// public:
//     int fun(vector<vector<int>>& matrix,int n,int m,int i,int j,vector<vector<int>>&dp){

//         if(i>=n || j>=m || j<0)
//         return INT_MAX;

//         if(i==n-1)
//         return dp[i][j]= matrix[i][j];

//         if(dp[i][j]!=-1)
//         return dp[i][j];

//         return dp[i][j] = matrix[i][j] + min(fun(matrix,n,m,i+1,j,dp) , 
//                 min(fun(matrix,n,m,i+1,j+1,dp) , fun(matrix,n,m,i+1,j-1,dp)));
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
        
//         int n = matrix.size();
//         int m = matrix[0].size();
//         int ans = INT_MAX;

//         vector<vector<int>>dp(n,vector<int>(m,-1));

//         for(int i=0;i<m;i++){
//             ans=min(ans,fun(matrix,n,m,0,i,dp));
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        
        for (int j = 0; j < n; ++j) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int left, up, right;

                if (j > 0) {
                    left = dp[i-1][j-1];
                } else {
                    left = INT_MAX;
                }

                up = dp[i-1][j];

                if (j < n - 1) {
                    right = dp[i-1][j+1];
                } else {
                    right = INT_MAX;
                }

                dp[i][j] = matrix[i][j] + min({left, up, right});
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(dp[n-1][i],mini);
        }
        return mini;
        
    }
};
