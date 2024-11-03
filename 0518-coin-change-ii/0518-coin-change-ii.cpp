class Solution {
public:
    int fun(vector<int>& coins, int amount, int i, vector<vector<int>>& memo) {
        // Base cases
        if (amount == 0) return 1; // If no amount is left, no coins are needed
        if (amount < 0 || i >= coins.size())
         return 0; // Return large number if amount is negative or no coins left
        
        // Check if the result is already computed
        if (memo[i][amount] != -1) return memo[i][amount];
        
        // Option 1: Do not take the current coin
        int nottake = fun(coins, amount, i + 1, memo);
        
        // Option 2: Take the current coin if it can fit
        int take = 0;
        if (coins[i] <= amount) {
            take = fun(coins, amount - coins[i], i, memo); // Include this coin and continue with the same index
        }
        
        // Store the result in the memo table
        memo[i][amount] = take + nottake;
        return memo[i][amount];
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, -1));
        return fun(coins, amount, 0, memo);
        
    }
};