class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return s.empty() ? 0: fun(0,s,dp);    
    }
    int fun(int i, string &s,vector<int> &dp) {
    
        if(i >= s.length())
        return 1;

        if(s[i] == '0')
        return 0; 

        if(dp[i] != -1)
        return dp[i];

        if( i < s.length()-1 && (s[i]=='1'|| (s[i]=='2'&& s[i+1]<'7')))
        return dp[i] = fun(i+2,s,dp) + fun(i+1,s,dp);
        else
        return dp[i] = fun(i+1,s,dp);


    }
};