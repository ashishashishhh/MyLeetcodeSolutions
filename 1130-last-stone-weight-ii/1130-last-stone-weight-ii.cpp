class Solution {
public:
    // TLE
    // int fun(vector<int>& stones, int n, int i, int currSum)
    // {
    //     if(i == n)
    //     {
    //         if(currSum < 0) 
    //          return INT_MAX;
    //         else
    //          return currSum;
    //     }
    //     return min(fun(stones, n, i+1, currSum + stones[i]),
    //                 fun(stones, n, i+1, currSum - stones[i]));
    // }
    
    // int lastStoneWeightII(vector<int>& stones) {
    //     int n = stones.size();
       
    //     int minWeight = fun(stones, n, 0, 0);
    //     return minWeight;        
    // }

    int memo[30 + 1][3000 + 1];

    int fun(vector<int>& stones, int n, int i, int sum1, int sum2)
    {
        if(i == n)
        {
            return abs(sum1-sum2);
        }
        if(memo[i][sum1] != -1)
        {
            return memo[i][sum1];
        }
        return memo[i][sum1] = min(fun(stones, n, i+1, sum1 + stones[i], sum2), 
                                    fun(stones, n, i+1, sum1, sum2 + stones[i]));
    }

    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        memset(memo, -1, sizeof(memo));
        
        int minWeight = fun(stones, n, 0, 0, 0);
        return minWeight;        
    }
};