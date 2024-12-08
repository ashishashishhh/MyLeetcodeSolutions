class Solution {
public:
    vector<int> start;
    vector<vector<int>> dp;
    long solve(vector<vector<int>>& events,int i,int k){
        if(i>=events.size() || k==0)
            return 0;
        if(dp[i][k]!=-1)
            return dp[i][k];
        long not_attended=solve(events,i+1,k);
        int index=upper_bound(start.begin(),start.end(),events[i][1])-start.begin();
        long attended=events[i][2]+solve(events,index,k-1);
        return dp[i][k]=max(attended,not_attended);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        for(auto e:events)
            start.push_back(e[0]);
        dp.resize(events.size(),vector<int>(3,-1));
        return solve(events,0,2);
    }
};