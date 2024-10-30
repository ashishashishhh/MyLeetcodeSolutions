class Solution {
public:
    int res(vector<vector<int>>& matrix,int i,int j,vector<vector<int>> &dp){
        if (i < 0 or i >= matrix.size() or 
        j < 0 or j >= matrix[0].size() or matrix[i][j] == 0)       
        return 0;


        if(dp[i][j]!=-1)
        return dp[i][j];

        dp[i][j] = 1 + min(res(matrix,i,j+1,dp),min(res(matrix,i+1,j,dp),res(matrix,i+1,j+1,dp)));

        return dp[i][j];
    }
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==1){
                    ans+=res(matrix,i,j,memo);
                }
            }
        }
        return ans;
    }
};