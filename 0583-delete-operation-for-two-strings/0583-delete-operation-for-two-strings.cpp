#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int fun(string& word1, string& word2, int i, int j, vector<vector<int>>& memo) {
        // Base cases
        if (i == word1.length() && j == word2.length())
            return 0;

        if (i == word1.length())
            return word2.length() - j;

        if (j == word2.length())
            return word1.length() - i;

        // Check if already computed
        if (memo[i][j] != -1)
            return memo[i][j];

        // If characters match, move to the next characters in both words
        if (word1[i] == word2[j]) {
            memo[i][j] = fun(word1, word2, i + 1, j + 1, memo);
        } else {
            // Otherwise, consider insert/delete operations and take the minimum
            memo[i][j] = 1 + min(fun(word1, word2, i + 1, j, memo), fun(word1, word2, i, j + 1, memo));
        }

        return memo[i][j];
    }

    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        // Initialize memoization table with -1 to indicate uncomputed values
        vector<vector<int>> memo(n, vector<int>(m, -1));
        return fun(word1, word2, 0, 0, memo);
    }
};
