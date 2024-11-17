class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
             vector<vector<int>> output;

        int newStart = newInterval[0];
        int newEnd = newInterval[1];

        int i = 0;
        int n = intervals.size();

        // Add all intervals that come before the new interval
        while (i < n && newStart > intervals[i][0]) {
            output.push_back(intervals[i]);
            i++;
        }

        // Merge newInterval with the last interval in output if necessary
        if (output.empty() || output.back()[1] < newStart) {
            output.push_back(newInterval);
        } else {
            output.back()[1] = max(output.back()[1], newEnd);
        }

        // Add remaining intervals, merging if necessary
        while (i < n) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if (output.back()[1] < start) {
                output.push_back(intervals[i]);
            } else {
                output.back()[1] = max(output.back()[1], end);
            }
            i++;
        }

        return output;
    }
};