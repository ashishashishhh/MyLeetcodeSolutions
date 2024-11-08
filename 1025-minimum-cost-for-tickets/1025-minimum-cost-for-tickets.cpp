class Solution { 
public:
vector<int> dp;
    int sub(vector<int> &day, vector<int> &cost, int si)   
    {
        int n = day.size();
        if(si>=n)
           return 0;
        
        if(dp[si])
          return dp[si]; 
        
        int cost_day = cost[0] + sub(day , cost , si+1);
        
        int i = si;

        while(i<n && day[i]<day[si]+7)
          i++;

        int cost_week = cost[1] + sub(day, cost, i);
        
        while(i<n && day[i]<day[si]+30)
          i++;
          
        int cost_month = cost[2] + sub(day, cost, i);     
        
        dp[si] = min({cost_day, cost_week , cost_month  });

        return dp[si];
    } 
    int mincostTickets(vector<int>& days, vector<int>& costs) {        
        dp.resize(367);
        return sub(days,costs,0);    
    }

};