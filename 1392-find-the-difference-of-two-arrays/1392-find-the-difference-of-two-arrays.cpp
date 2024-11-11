class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& arr1, vector<int>& arr2) {
        
               
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        
         auto it1 = unique(arr1.begin(), arr1.end());
         auto it2 = unique(arr2.begin(), arr2.end());
         
         arr1.erase(it1, arr1.end());
         arr2.erase(it2, arr2.end());
         
        vector<int> dp;
        vector<int> dp2;
       
        
        for(auto i : arr1){
             auto it = find(arr2.begin(), arr2.end(), i);
             if(it != arr2.end()){
                 NULL;
             }
             else{
                 dp.push_back(i);
             }
        }
        
        for(auto i : arr2){
             auto it = find(arr1.begin(), arr1.end(), i);
             if(it != arr1.end()){
                 NULL;
             }
             else{
                 dp2.push_back(i);
             }
        }
        
        return {dp,dp2};

    }
};