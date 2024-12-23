class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); 
        unordered_set<int>st;
        int last = INT_MIN;
        for(int num:nums){
           int curr = max(last + 1 , num - k);
           cout<<curr<<endl;
           if(curr<=num + k){
            st.insert(curr);
            last = curr;
           }

        }
        return st.size();
    }
};