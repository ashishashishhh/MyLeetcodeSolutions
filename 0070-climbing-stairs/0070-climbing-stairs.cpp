class Solution {
public:
    int fun(int n,int d,unordered_map<int, int> &memo){
        if(d==n)
        return 1;
        if(d>n)
        return 0;
        if (memo.find(d) != memo.end()) {
            return memo[d];
        }
        return memo[d] = fun(n,d+1,memo) + fun(n,d+2,memo);
    }
    int climbStairs(int n) {
        unordered_map<int, int> memo;
        return fun(n,0,memo);
    }
};