class Solution {
public:
    unordered_map<int,int>mp;
    int dp[7001][2];
    int solve(int i,int a,int b,int x,bool back)
    {
      if(i==x)return 0;
      if((i<0) || (i>6000) || (mp.find(i)!=mp.end()))
      {
        return 1e9;
      }
      if(dp[i][back]!=-1)return dp[i][back];
      //go forword
      dp[i][back]=1+solve(i+a,a,b,x,false);
      
      if(back==false) dp[i][back]=min(dp[i][back],1+solve(i-b,a,b,x,true));
      
      return dp[i][back];
      
    }
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        for(int f:forbidden)mp[f]++;
        memset(dp,-1,sizeof(dp));
        int res=solve(0,a,b,x,false);
        if(res>=1e9)return -1;
        return res;
        
    }
};