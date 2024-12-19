class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
       int n = nums.size();
    vector<int> result(n);

    for (int i = 0; i < n; ++i) {
        if (nums[i] > 0) {
            int targetIndex = (i + nums[i]) % n; // Safe for positive numbers
            result[i] = nums[targetIndex];
        } else if (nums[i] < 0) {
            int targetIndex = ((i + nums[i]) % n + n) % n; // Normalize negative indices
            result[i] = nums[targetIndex];
        } else {
            result[i] = nums[i];
        }
    }

    return result;
        
    }
};