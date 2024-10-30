class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;

        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 10;

        int uniq = 9;
        int avail = 9;

        for (int i = 2; i <= n; i++) {
            uniq *= avail;
            dp[i] = dp[i - 1] + uniq;
            avail--;
        }

        return dp[n];
    }
};
