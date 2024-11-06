// #include <vector>
// using namespace std;

// class Solution {
// public:
//     int numberOfArithmeticSlices(vector<int>& nums) {
//         if (nums.size() < 3) return 0; // Edge case for arrays with fewer than 3 elements
        
//         int totalCount = 0;
//         countArithmeticSlices(nums, nums.size() - 1, totalCount);
//         return totalCount;
//     }
    
//     int countArithmeticSlices(const vector<int>& nums, int i, int& totalCount) {
//         // Base case: If there are fewer than 3 elements, there are no arithmetic slices
//         if (i < 2)
//          return 0;

//         int current = 0;
//         // Check if the last three elements form an arithmetic sequence
//         if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
//             current = 1 + countArithmeticSlices(nums, i - 1, totalCount);
//             cout<<current<<endl;
//             totalCount += current; // Add the current count to the total
//         } else {
//             // Reset the current count if it's not an arithmetic sequence
//             countArithmeticSlices(nums, i - 1, totalCount);
//         }

//         return current;
//     }
// };

class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>& dp)  {
        if (i < 2) {
            return 0;
        }
        int &val = dp[i];
        if (val != -1) {
            return val;
        }
        if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
            return val = solve(nums, i - 1, dp) + 1;
        }
        return val = 0;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int n = nums.size();
        int ans = 0;
        vector<int> dp(n, -1);
        for (int i = 0; i < n; i++) {
            ans += solve(nums, i, dp);
            cout<<ans<<endl;
        }
        return ans;
    }
};
// Time complexity: O(N)
// Space complexity: O(N)
