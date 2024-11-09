// TLE
// class Solution {
// public:
//     int helper(int target, int fuel, vector<vector<int>>& s, int i, int prev_stop, vector<vector<vector<int>>> &dp){
        
//         if(target <= fuel)
//          return 0;
        
//         if(i == s.size())
//          return INT_MAX-1;
        
//         int distance = s[i][0] - prev_stop;
        
//         if(fuel < distance )
//           return INT_MAX-1;
        
//         if(dp[target][fuel][i] != -1)
//          return dp[target][fuel][i];
        
        
//         int take_fuel = 1 + helper(target - distance, fuel + s[i][1] - distance, s, i+1, s[i][0], dp);
//         int not_take_fuel = helper(target, fuel, s, i+1, prev_stop, dp);
        
        
//         return dp[target][fuel][i] = min(take_fuel, not_take_fuel);
//     }    

//     int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
//         int n = stations.size();
//         vector<vector<vector<int>>> dp(target+1, vector<vector<int>>(target+1, vector<int>(n+1, -1)));
        
//         int ans = helper(target, startFuel, stations, 0, 0, dp);
        
//         if(ans == INT_MAX-1) return -1;
        
//         return ans;
//     }
// };



class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n=stations.size();
        int prsntFl=startFuel, i=0; 
        int ans=0;
        priority_queue<int> p;
        while(prsntFl < target){
            while(i<n && prsntFl >= stations[i][0]){
                p.push(stations[i][1]);
                i++;
            }
            if(p.empty())
             return -1;
            prsntFl += p.top();
            p.pop();
            cout<<i<<endl;
            ans++;
        }
        return ans;
    }
};