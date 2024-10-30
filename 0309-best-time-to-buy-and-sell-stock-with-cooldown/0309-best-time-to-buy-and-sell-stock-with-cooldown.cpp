class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
        return solve(0, 1, prices,dp);
    }

    int solve(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (ind >= prices.size()) 
        return 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        int profit = 0;
        if (buy == 1) {
            int op1 = -prices[ind] + solve(ind + 1, 0, prices,dp);
            int op2 = solve(ind + 1, 1, prices,dp);
            profit = max(op1, op2);
        } else {
            int op1 = prices[ind] + solve(ind + 2, 1, prices,dp);
            int op2 = solve(ind + 1, 0, prices,dp);
            profit = max(op1, op2);
        }
        dp[ind][buy] = profit;
        return dp[ind][buy];
    }
};