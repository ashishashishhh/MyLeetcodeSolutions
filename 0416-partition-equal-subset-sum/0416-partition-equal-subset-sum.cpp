class Solution {
public:
    int dp[205][20005];
    int fun(vector<int>& nums,int i,int sum){

        if(i>=nums.size())
        return 0;

        if(sum==0)
        return 1;

        if(sum<0)
        return 0;

        if(dp[i][sum]!=-1)
        return dp[i][sum];


        return dp[i][sum] = fun(nums,i+1,sum-nums[i]) || fun(nums,i+1,sum);
    


    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        sum+=nums[i];

        if(sum%2!=0)
        return false;

        memset(dp,-1,sizeof(dp));

        return fun(nums,0,sum/2);
        
    }
};