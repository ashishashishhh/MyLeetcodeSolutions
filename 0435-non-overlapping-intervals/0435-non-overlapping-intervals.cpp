class Solution {
public:
    #include <vector>
#include <algorithm>

int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
    if (intervals.empty()) return 0;

    // Sort intervals by their end time
    std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] < b[1];
    });

    int removeCount = 0;
    int end = intervals[0][1]; // Initialize end time with the end of the first interval

    // Traverse through intervals
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] < end) {
            // Overlap, so we need to remove this interval
            removeCount++;
        } else {
            // No overlap, update end to the end of the current interval
            end = intervals[i][1];
        }
    }

    return removeCount;
}

};