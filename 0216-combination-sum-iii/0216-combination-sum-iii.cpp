class Solution {
public:
    void findcombination(int ind, int size,int target, vector<int> &arr,vector<vector<int>> &ans, vector<int> &ds){
        if(ind >= arr.size()){
            if(target==0 && ds.size()==size)
                ans.push_back(ds);
            return;
        }
        if(arr[ind]<=target){
            ds.push_back(arr[ind]);
            findcombination(ind + 1,size, target-arr[ind], arr, ans, ds);
            ds.pop_back();
        }
        findcombination(ind+1, size,target, arr, ans, ds);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int>candidates;
        for(int i=0;i<9;i++)
        candidates.push_back(i+1);
        findcombination(0, k,n, candidates, ans, ds);
        return ans;
    }
};