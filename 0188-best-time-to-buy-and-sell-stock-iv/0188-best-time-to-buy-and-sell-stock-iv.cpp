class Solution {
public:
    int fun(vector<int>& prices, int i, int buy, int cap, vector<vector<vector<int>>>& dp) {
        // Base cases
        if (i >= prices.size() || cap == 0) {
            return 0;
        }

        // Check if the result is already computed
        if (dp[i][buy][cap] != -1) {
            return dp[i][buy][cap];
        }

        int profit = 0;
        if (buy == 1) {
            // Option to buy or skip
            profit = max(-prices[i] + fun(prices, i + 1, 0, cap, dp), 
                         fun(prices, i + 1, 1, cap, dp));
        } else {
            // Option to sell or skip
            profit = max(prices[i] + fun(prices, i + 1, 1, cap - 1, dp), 
                         fun(prices, i + 1, 0, cap, dp));
        }

        // Memoize the result
        dp[i][buy][cap] = profit;
        return profit;
    }

    int maxProfit(int k,vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return fun(prices, 0, 1, k, dp);
    }
};
