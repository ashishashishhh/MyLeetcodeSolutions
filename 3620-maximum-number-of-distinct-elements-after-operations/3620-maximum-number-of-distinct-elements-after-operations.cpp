class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); 
        int count = 0;
        int last = INT_MIN;
        for(int num:nums){
           int curr = max(last + 1 , num - k);
           if(curr<=num + k){
            count++;
            last = curr;
           }

        }
        return count;
    }
};