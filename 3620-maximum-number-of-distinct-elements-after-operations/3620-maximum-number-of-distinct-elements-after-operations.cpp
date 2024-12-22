class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end()); // Sort the input array
    int lastUsed = INT_MIN; // Track the largest adjustment used so far
    int count = 0; // Count of unique adjustments

    for (int num : nums) {
        // Choose the maximum of num - k or lastUsed + 1 as the next valid adjustment
        int adjustment = max(num - k, lastUsed + 1);
        if (adjustment <= num + k) {
            lastUsed = adjustment; // Update lastUsed to the chosen adjustment
            ++count; // Increment the count of unique adjustments
        }
    }

    return count; // Return the count of unique adjustments
    }
};