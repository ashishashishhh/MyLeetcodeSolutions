class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1)
        return 1;
        int ans = -1;
        vector<int>incount(n+1,0);
        vector<int>outcount(n+1,0);
        for(int i=0;i<trust.size();i++){
            incount[trust[i][0]]++;
            outcount[trust[i][1]]++;
        }
        for(int i=0;i<n+1;i++){
            if(incount[i]==0 && outcount[i]==n-1)
            return i;
        }
        return ans;
        
    }
};