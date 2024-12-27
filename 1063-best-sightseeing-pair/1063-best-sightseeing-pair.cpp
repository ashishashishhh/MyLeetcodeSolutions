class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int diff = INT_MIN ,value = values[0] , index = 0;
        for(int i=1;i<values.size();i++){
            diff = max(diff , values[i] + value + index - i);
            if((values[i] + i) >= (value + index)){
                value = values[i];
                index = i;
            }
        }
        return diff;
    }
};