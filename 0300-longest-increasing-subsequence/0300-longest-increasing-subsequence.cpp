class Solution {
public:
    int fun(vector<int>& nums,int i,int prev,vector<vector<int>>&dp){
        if(i>=nums.size())
        return 0;

        if(dp[i][prev+1]!=-1)
        return dp[i][prev+1];

        int notake = fun(nums,i+1,prev,dp);
        int take;
        if(prev==-1 || nums[i]>nums[prev])
        take =  1 + fun(nums,i+1,i,dp);

        return dp[i][prev+1] = max(take,notake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev = -1;
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        return fun(nums,0,prev,dp);
        
    }
};