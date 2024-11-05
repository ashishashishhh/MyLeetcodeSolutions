#include <vector>
#include <string>
#include <utility>

class Solution {
public:
    pair<int, int> cou(const string& s) {
        int zero = 0, one = 0;
        for (char c : s) {
            if (c == '0') zero++;
            else one++;
        }
        return {zero, one};
    }

    int fun(vector<string>& strs, int m, int n, int i, vector<vector<vector<int>>>& dp) {
        if (i >= strs.size()) return 0;

        // Check memoization table
        if (dp[i][m][n] != -1) return dp[i][m][n];

        // Option 1: Do not take the current string
        int notake = fun(strs, m, n, i + 1, dp);

        // Option 2: Take the current string if possible
        int take = 0;
        auto [countZero, countOne] = cou(strs[i]);
        if (countZero <= m && countOne <= n) {
            take = 1 + fun(strs, m - countZero, n - countOne, i + 1, dp);
        }

        // Memoize and return the result
        return dp[i][m][n] = max(take, notake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        // Initialize memoization table with -1 (uncomputed states)
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return fun(strs, m, n, 0, dp);
    }
};
