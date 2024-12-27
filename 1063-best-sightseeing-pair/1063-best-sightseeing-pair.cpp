class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        if (n < 2)
         return values[0] + values[1] + 0 - 1; 
        int diff = INT_MIN;
        int value = values[0];
        int index = 0;
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