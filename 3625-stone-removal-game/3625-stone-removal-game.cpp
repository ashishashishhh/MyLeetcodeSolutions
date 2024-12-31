class Solution {
public:
    bool canAliceWin(int n) {
        int curr = 10;
        bool ans = false;
        while(n>=curr){
            n=n-curr;
            curr--;
            if(ans)
            ans=false;
            else
            ans=true;
        }
        return ans;
        
    }
};