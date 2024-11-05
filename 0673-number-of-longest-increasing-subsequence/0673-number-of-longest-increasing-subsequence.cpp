class Solution
{
    public:
    pair<int, int> f(vector<int>& nums, int i, int prev,vector<vector<pair<int, int>>>& dp) {
        if (i >= nums.size())
            return {0, 1};

        if (dp[prev + 1][i].first != -1)
            return dp[prev + 1][i];
        
        pair<int, int> a = {0, 0}, b = {0, 0};

        if (prev == -1 || nums[i] > nums[prev]) {
            a = f(nums, i + 1, i, dp);
            a.first++;
        }

        b = f(nums, i + 1, prev, dp);
    
        if (a.first == b.first) {
            dp[prev + 1][i] = {a.first, a.second + b.second};
        } 
        else if (a.first > b.first) {
            dp[prev + 1][i] = a;
        } else {
            dp[prev + 1][i] = b;
        }
        return dp[prev + 1][i];
    }

    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(n, {-1, -1}));
        return f(nums, 0, -1, dp).second;
    }
};