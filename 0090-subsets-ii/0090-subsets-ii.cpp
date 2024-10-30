class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> subs;
        vector<int> currvec;
        subsets(nums, 0, currvec, subs);
        return subs;
    }
private:
    void subsets(vector<int> nums, int i, vector<int> currvec, vector<vector<int>>& subs) {
	
        subs.push_back(currvec);
		
        for (int j = i; j < nums.size(); j++) {
            if(j>i && nums[j]==nums[j-1])
                continue;
            currvec.push_back(nums[j]);
            subsets(nums, j + 1, currvec, subs);
            currvec.pop_back();
        }
    }
};