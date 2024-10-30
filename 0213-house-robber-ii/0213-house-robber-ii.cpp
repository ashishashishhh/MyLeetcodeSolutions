class Solution {
public:
    int rec(vector<int>& nums, int index, int range,vector<int>& dp){

        if(index>range)
            return 0;
        
        
        if(dp[index]!=-1)
            return dp[index];

        int include= nums[index]+ rec(nums, index+2,range,dp);
        int exclude= rec(nums,index+1,range,dp);

        return dp[index]= max(include,exclude);

    }
   
    int rob(vector<int>& nums) {

        vector<int> dp1(nums.size()+1,-1);
        vector<int> dp2(nums.size()+1,-1);

        if(nums.size()==1)
        return nums[0];
     
        int include= rec(nums,0,nums.size()-2,dp1);
        int exclude= rec(nums,1,nums.size()-1,dp2); 
        return max(include,exclude);  
    }
};