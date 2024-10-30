class Solution {
public:
    unordered_map<string, vector<int>>dp;
    vector<int> solve(string s)
    {
        if(dp.find(s) != dp.end())
         return dp[s];
        vector<int>ans;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '+' or s[i] == '-' or s[i] == '*')
            {
                auto left = solve(s.substr(0, i));
                auto right = solve(s.substr(i + 1));

                for(auto &l:left)
                {
                    for(auto &r:right)
                    {
                        if(s[i] == '+')
                            ans.push_back(l + r);
                        if(s[i] == '-')
                            ans.push_back(l - r);
                        if(s[i] == '*')
                            ans.push_back(l * r);
                    }
                }
            }
        }
        if(ans.empty()) ans.push_back(stoi(s));
        return dp[s] = ans;
    }
    vector<int> diffWaysToCompute(string s) 
    {
        return solve(s);
    }
};