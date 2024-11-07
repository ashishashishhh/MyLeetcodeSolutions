class Solution {
public:
    int dp[71][5000];
    int rec(int row,int m,int n,int sum,vector<vector<int>>& mat,int target) {
        if(row==m) {
            return abs(sum-target);
        }
        if(dp[row][sum]!=-1)
         return dp[row][sum];
        int ans = 1e9;
        for(int col=0;col<n;col++) {
            ans = min(ans,rec(row+1,m,n,sum+mat[row][col],mat,target));
        }
        return dp[row][sum] = ans;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();
        memset(dp,-1,sizeof(dp));
        return rec(0,m,n,0,mat,target);
    }
};