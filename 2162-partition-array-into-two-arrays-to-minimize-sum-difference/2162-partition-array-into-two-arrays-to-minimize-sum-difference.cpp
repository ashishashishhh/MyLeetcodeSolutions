
// class Solution {
// public:
//     int minimumDifference(vector<int>& nums) {
//         int sum = 0;
//         for (int a : nums)
//             sum += a;
        
//         int ans = 1e8;
//         memo.clear();
//         solve(nums.size() - 1, 0, nums.size() / 2, sum, ans, nums);
        
//         return ans;
//     }

// private:
//     unordered_map<string, int> memo; // Memoization map

//     int solve(int idx, int sum, int len, int total, int& ans, const vector<int>& arr) {
//         if (len == 0) {
//             ans = min(ans, abs(total - 2 * sum));
//             return ans;
//         }

//         if (idx == 0) return 1e8; // Large number as a placeholder for invalid cases

//         // Create a unique key for memoization
//         string key = to_string(idx) + "," + to_string(sum) + "," + to_string(len);
//         if (memo.find(key) != memo.end())
//             return memo[key];

//         // Recursively solve with and without including current element
//         int include = solve(idx - 1, sum + arr[idx], len - 1, total, ans, arr);
//         int exclude = solve(idx - 1, sum, len, total, ans, arr);

//         memo[key] = ans; // Store result in memo
//         return ans;
//     }
// };


class Solution {
public:
int minimumDifference(vector<int>& nums) {
    int n = nums.size(),  sum = 0;
    sum = accumulate(nums.begin(), nums.end(),0);  // To find the total sum of the array 
    
    int N = n/2; // Divide it into two equals parts as length is even
    vector<vector<int>> left(N+1), right(N+1); // left array and right array
    
	//All possible sum in left and right part (Generating and storing using BIT-Masking)
    for(int mask = 0; mask<(1<<N); ++mask){  // (1<<n) means 2^n i.e we'll iterate through 0 to 2^n
        int idx = 0, l_sum = 0, r_sum = 0;
        for(int i=0; i<N; ++i){
            if(mask&(1<<i)){  // To check if the bit is set or not 
                idx++;
                l_sum += nums[i];
                r_sum += nums[i+N];
            }
        }
        left[idx].push_back(l_sum);
        right[idx].push_back(r_sum);   // storing
    }

    for(int idx=0; idx<=N; ++idx){
        sort(right[idx].begin(), right[idx].end());   // as we'll perform binary search on right so we have to sort it first
    }

 int res = min(abs(sum-2*left[N][0]), abs(sum-2*right[N][0]));  // To get the minimum answer from the max sum from both array
		//iterating over left part
		for(int idx=1; idx<N; ++idx){ // iterate from 1 so we dont have to include 0 and check for all value except last as we have alr considered it
			for(auto &a : left[idx]){ // check the sum at each number position
				int b = (sum - 2*a)/2; // find the value to be minimized 
				int rightidx = N-idx; // find the number value in right array
				auto &v = right[rightidx]; // store the vector in v at right number position
				auto itr = lower_bound(v.begin(), v.end(),b); //binary search over right part

				if(itr!=v.end()) res = min(res, abs(sum-2*(a+(*itr)))); // if found in vector then only update otherwise continue

				}                
			}
		return res;

	}
};