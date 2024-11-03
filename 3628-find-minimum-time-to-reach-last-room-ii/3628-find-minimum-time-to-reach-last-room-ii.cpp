// TLE
// #include <vector>
// #include <algorithm>
// #include <climits>
// using namespace std;

// class Solution {
//     int n, m;
//     vector<vector<int>> memo; 
//     int dfs(vector<vector<int>>& moveTime, int i, int j, int time) {
        
//         if (i == n - 1 && j == m - 1)
//          return time;

     
//         if (memo[i][j] <= time)
//          return INT_MAX;

//         memo[i][j] = time; 

//         int minTime = INT_MAX;
        
//         if (i > 0) {
//             int newTime = max(time , moveTime[i - 1][j]);
//             if((i+j)%2==0)
//             minTime = min(minTime, dfs(moveTime, i - 1, j, newTime+1));
//             else
//             minTime = min(minTime, dfs(moveTime, i - 1, j, newTime+2));
//         }
//         if (j > 0) {
//             int newTime = max(time, moveTime[i][j - 1]);
//             if((i+j)%2==0)
//             minTime = min(minTime, dfs(moveTime, i, j - 1, newTime+1));
//             else
//             minTime = min(minTime, dfs(moveTime, i, j - 1, newTime+2));
//         }
//         if (i < n - 1) {
//             int newTime = max(time, moveTime[i + 1][j]);
//             if((i+j)%2==0)
//             minTime = min(minTime, dfs(moveTime, i + 1, j, newTime+1));
//             else
//             minTime = min(minTime, dfs(moveTime, i + 1, j, newTime+2));
//         }
//         if (j < m - 1) {
//             int newTime = max(time, moveTime[i][j+1]);
//             if((i+j)%2==0)
//             minTime = min(minTime, dfs(moveTime, i, j + 1, newTime+1));
//             else
//             minTime = min(minTime, dfs(moveTime, i, j + 1, newTime+2));
//         }

        
//         return minTime;
//     }

// public:
//     int minTimeToReach(vector<vector<int>>& moveTime) {
//         n = moveTime.size();
//         m = moveTime[0].size();
       
//         memo.assign(n, vector<int>(m, INT_MAX));
//         return dfs(moveTime, 0, 0, 0);
//     }
// };


#include <vector>
#include <queue>
#include <tuple>
#include <set>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size() - 1, n = moveTime[0].size() - 1;
        priority_queue<tuple<int, int, int, bool>, vector<tuple<int, int, int, bool>>, greater<>> heap;
        heap.push({0, 0, 0, true});
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        set<pair<int, int>> visited;
        while (!heap.empty()) {
            auto [time, r, c, check] = heap.top();
            heap.pop();
            if (r == m && c == n) return time;
            int newTime = check ? 1 : 2;
            for (auto& dir : directions) {
                int row = r + dir[0], col = c + dir[1];
                if (row <= m && col <= n && row >= 0 && col >= 0 && !visited.count({row, col})) {
                    heap.push({max(time, moveTime[row][col]) + newTime, row, col, !check});
                    visited.insert({row, col});
                }
            }
        }
        return -1;
    }
};