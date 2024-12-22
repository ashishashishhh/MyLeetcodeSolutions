class Solution {
public:
    int minimumOperations(vector<int>& nums) {
         unordered_set<int> uniqueElements(nums.begin(), nums.end());
    if (uniqueElements.size() == nums.size()) {
        return 0; // Already distinct
    }

    int operations = 0;
    while (!nums.empty()) {
        nums.erase(nums.begin(), nums.begin() + min(3, (int)nums.size()));
        operations++;
        uniqueElements = unordered_set<int>(nums.begin(), nums.end());
        if (uniqueElements.size() == nums.size()) {
            break; // No duplicates left
        }
    }
    return operations;
    }
};