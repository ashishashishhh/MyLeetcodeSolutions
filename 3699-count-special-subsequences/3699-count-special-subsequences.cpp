// class Solution {
// public:
//     void fun(const vector<int>& nums, vector<int>& current, int index, vector<vector<int>>& result) {

//         if (current.size() == 4) {
//             result.push_back(current);
//             return;
//         }

//         for (int i = index; i < nums.size(); ++i) {
//             if (current.empty() || i - current.back() > 1) {
//                 current.push_back(i); 
//                 fun(nums, current, i + 1, result); 
//                 current.pop_back(); 
//             }
//         }
//     }
    
//     long long numberOfSubsequences(vector<int>& nums) {
//         vector<vector<int>> result; 
//         vector<int> current;   
//         fun(nums, current, 0, result);
//         int count = 0;

//         for (int i=0;i<result.size();i++) {
//             int p = result[i][0];
//             int q =result[i][1];
//             int r = result[i][2];
//             int s = result[i][3];
//             if(nums[p]*nums[r] == nums[q]*nums[s]){
//                 count++;
//             }
//         }
//         return count;
//     }
// };


class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
    unordered_map<double, long long> freq;
    long long ans = 0;
    for(int r = 4; r < nums.size(); ++r){
        for(int p = 0, q = r - 2; p < q-1; ++p) freq[(double)nums[p]/(double)nums[q]]++;
        for(int s = r + 2; s < nums.size(); ++s) ans += freq[(double)nums[s]/(double)nums[r]];
    }
    return ans;
}
};