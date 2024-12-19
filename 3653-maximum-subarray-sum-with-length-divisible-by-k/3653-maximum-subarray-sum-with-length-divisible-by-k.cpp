class Solution {
public:
    
    const long long INF = 1e18; 
    
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(); 
        long long ans = -INF; 
        vector<long long> dp(k, INF); 
        long long currSum = 0; 
        for (int i = 0; i < n; i++) {
            currSum += nums[i]; 
        
            ans = max(ans, currSum - dp[i % k]);

            if ((i + 1) % k == 0) {
                ans = max(ans, currSum); 
            }
            dp[i % k] = min(1LL * dp[i % k], currSum); 
        }
        return ans; 
    }
};