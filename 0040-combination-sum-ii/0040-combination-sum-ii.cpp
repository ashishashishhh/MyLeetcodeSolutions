class Solution {
public:

    vector<vector<int>> res;
    
    void solve(vector<int>& candidates, vector<int> &s,int index ,int target)
    {
        if(target<0)
            return ;
        if(target==0)
        {
            res.push_back(s);
            return ;
        }
        
        for(int i=index;i<candidates.size();i++)
        {
            if(i>index && candidates[i]==candidates[i-1])
                continue;
            s.push_back(candidates[i]);
            solve(candidates,s,i+1,target-candidates[i]);
            s.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> s;
        int index=0;
        solve(candidates,s,index,target);
        return res;
    }
};