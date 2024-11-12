
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> ans;
        sort(items.begin(), items.end());
        vector<int> beauty;
        int maxbeauty = items[0][1];
        beauty.push_back(maxbeauty);

        for (int i = 1; i < items.size(); i++) {
            maxbeauty = max(items[i][1], maxbeauty);
            beauty.push_back(maxbeauty);
        }

        for (int i = 0; i < queries.size(); i++) {
            auto val = upper_bound(items.begin(), items.end(), vector<int>{queries[i], INT_MAX}) - items.begin();
            if (val) {
                val--;
                ans.push_back(beauty[val]);
            } else {
                ans.push_back(0);
            }
        }

        return ans;
    }
};