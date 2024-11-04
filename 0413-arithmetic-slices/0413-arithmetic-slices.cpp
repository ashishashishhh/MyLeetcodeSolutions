#include <vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0; // Edge case for arrays with fewer than 3 elements
        
        int totalCount = 0;
        countArithmeticSlices(nums, nums.size() - 1, totalCount);
        return totalCount;
    }
    
    int countArithmeticSlices(const vector<int>& nums, int i, int& totalCount) {
        // Base case: If there are fewer than 3 elements, there are no arithmetic slices
        if (i < 2)
         return 0;

        int current = 0;
        // Check if the last three elements form an arithmetic sequence
        if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
            current = 1 + countArithmeticSlices(nums, i - 1, totalCount);
            totalCount += current; // Add the current count to the total
        } else {
            // Reset the current count if it's not an arithmetic sequence
            countArithmeticSlices(nums, i - 1, totalCount);
        }

        return current;
    }
};
