class Solution {
public:
    int fun(vector<int>& coins, int amount, int i, vector<vector<int>>& memo) {
        // Base cases
        if (amount == 0)
         return 1; 
        if (amount < 0 || i >= coins.size())
         return 0; 
        
     
        if (memo[i][amount] != -1)
         return memo[i][amount];
        
        int nottake = fun(coins, amount, i + 1, memo);
        
        int take = 0;
        if (coins[i] <= amount) {
            take = fun(coins, amount - coins[i], i, memo); 
        }
        
        memo[i][amount] = take + nottake;
        return memo[i][amount];
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, -1));
        return fun(coins, amount, 0, memo);
    }
};