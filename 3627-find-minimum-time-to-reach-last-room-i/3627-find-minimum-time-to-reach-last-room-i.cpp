#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
    int n, m;
    vector<vector<int>> memo; 
    int dfs(vector<vector<int>>& moveTime, int i, int j, int time) {
        
        if (i == n - 1 && j == m - 1)
         return time;

     
        if (memo[i][j] <= time)
         return INT_MAX;

        memo[i][j] = time; 

        int minTime = INT_MAX;
        
        if (i > 0) {
            int newTime = max(time , moveTime[i - 1][j]);
            minTime = min(minTime, dfs(moveTime, i - 1, j, newTime+1));
        }
        if (j > 0) {
            int newTime = max(time, moveTime[i][j - 1]);
            minTime = min(minTime, dfs(moveTime, i, j - 1, newTime+1));
        }
        if (i < n - 1) {
            int newTime = max(time, moveTime[i + 1][j]);
            minTime = min(minTime, dfs(moveTime, i + 1, j, newTime+1));
        }
        if (j < m - 1) {
            int newTime = max(time, moveTime[i][j+1]);
            minTime = min(minTime, dfs(moveTime, i, j + 1, newTime+1));
        }

        
        return minTime;
    }

public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        n = moveTime.size();
        m = moveTime[0].size();
       
        memo.assign(n, vector<int>(m, INT_MAX));
        return dfs(moveTime, 0, 0, 0);
    }
};