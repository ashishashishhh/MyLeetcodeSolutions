class Solution {
public:
    int minimizeArrayValue(vector<int>& A) {
        long sum = 0, res = 0;
        for (int i = 0; i < A.size(); ++i) {
            sum += A[i];
            if(sum%(i+1)==0)
            res = max(res,sum/(i+1));
            else
            res = max(res,1 + sum/(i+1));
        }
        return res;
    }
};