class Solution {
public:

    int maxJump(vector<int>& stones) {
        int n=stones.size();
        //one unit jumps as stones.size()>=2
        int ans=max(stones[1]-stones[0],stones[n-1]-stones[n-2]);
        for(int i=0;i<n;i++) {
            if(i-2>=0) {
                ans=max(ans,stones[i]-stones[i-2]);
            }
        }
        return ans;
    }
};