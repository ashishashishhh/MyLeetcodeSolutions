class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {
        int x=0;
        for(int c:d)
         x^=c;
        return (!x);
    }
};