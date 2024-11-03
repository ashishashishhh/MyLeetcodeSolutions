class Solution {
public:
    int fun(vector<int>& coins, int amount, int i, vector<vector<int>>& memo) {
        // Base cases
        if (amount == 0) return 0; // If no amount is left, no coins are needed
        if (amount < 0 || i >= coins.size())
         return 1e8; // Return large number if amount is negative or no coins left
        
        // Check if the result is already computed
        if (memo[i][amount] != -1) return memo[i][amount];
        
        // Option 1: Do not take the current coin
        int nottake = fun(coins, amount, i + 1, memo);
        
        // Option 2: Take the current coin if it can fit
        int take = 1e8;
        if (coins[i] <= amount) {
            take = 1 + fun(coins, amount - coins[i], i, memo); // Include this coin and continue with the same index
        }
        
        // Store the result in the memo table
        memo[i][amount] = min(take, nottake);
        return memo[i][amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        // Memo table initialized to -1, with dimensions (coins.size() x (amount + 1))
        vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, -1));
        int result = fun(coins, amount, 0, memo);
        return result == 1e8 ? -1 : result;
    }
};
