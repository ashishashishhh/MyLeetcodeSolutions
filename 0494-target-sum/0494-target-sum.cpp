
class Solution {
public:
    int fun(vector<int>& nums, int i, int target, int sum, unordered_map<string, int>& memo) {
        if (i == nums.size())
            return sum == target ? 1 : 0;

        // Create a unique key for memoization
        string key = to_string(i) + "," + to_string(sum);

        // Check if the result is already in the memo
        if (memo.find(key) != memo.end())
            return memo[key];

        // Recursive calls with addition and subtraction
        int add = fun(nums, i + 1, target, sum + nums[i], memo);
        int sub = fun(nums, i + 1, target, sum - nums[i], memo);

        // Store the result in the memo before returning
        memo[key] = add + sub;

        return memo[key];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> memo;
        return fun(nums, 0, target, 0, memo);
    }
};