class Solution {
public:
    void fun(const vector<pair<int, int>>& sortedPairs, int target, vector<int>& ans) {
        int left = 0, right = sortedPairs.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (sortedPairs[mid].first >= target) {
                result = sortedPairs[mid].second;
                right = mid - 1;
            } else {
                left = mid + 1; 
            }
        }

        ans.push_back(result); 
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> sortedPairs;
        for (int i = 0; i < intervals.size(); ++i) {
         sortedPairs.emplace_back(intervals[i][0], i);
        }
        sort(sortedPairs.begin(), sortedPairs.end());
        vector<int>ans;
        for(int i=0;i<intervals.size();i++){
            fun(sortedPairs,intervals[i][1],ans);
        }
        return ans;
    }
};