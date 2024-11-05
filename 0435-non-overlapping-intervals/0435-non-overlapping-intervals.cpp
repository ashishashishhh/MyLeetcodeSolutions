class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int i=0,j=1,ans=0;
        while(i<intervals.size() && j<intervals.size())
        {
            int end = intervals[i][1];
            int start = intervals[j][0];
            if(end>start){
                ans++;
                j++;
            }
            else{
                i=j;
                j++;
            }
        }
        return ans;
        
    }
};