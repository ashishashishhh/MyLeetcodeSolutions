class Solution {
public:
    int calculateMinCost(int start, int end, std::vector<std::vector<int>>& memo) {
        if (start >= end) {
            return 0; // No cost if the range is invalid or has only one number
        }

        if (memo[start][end] != -1) {
            return memo[start][end]; // Return the stored result if already computed
        }

        int minCost = INT_MAX; // Initialize to maximum possible value

        // Try guessing every number in the range [start, end]
        for (int guess = start; guess <= end; ++guess) {
            // Calculate the cost for the current guess
            // Cost is the guess amount + max cost of guessing in either left or right subranges
            int cost = guess + max(calculateMinCost(start, guess - 1, memo), calculateMinCost(guess + 1, end, memo));
            
            // Update the minimum cost
            minCost = std::min(minCost, cost);
        }

        memo[start][end] = minCost; // Store the computed result in memoization table
        return minCost;
    }

    int getMoneyAmount(int n) {
        std::vector<std::vector<int>> memo(n + 1, std::vector<int>(n + 1, -1)); // Initialize memoization table
        return calculateMinCost(1, n, memo); // Start guessing from range 1 to n
    }
};