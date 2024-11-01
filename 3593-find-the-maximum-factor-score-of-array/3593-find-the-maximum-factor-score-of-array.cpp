#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return static_cast<long long>(nums[0]) * nums[0]; // If only one element, return its square (GCD * LCM = num * num)

        // Step 1: Calculate prefix and suffix GCD arrays
        vector<long long> prefixGCD(n, 0), suffixGCD(n, 0);
        prefixGCD[0] = nums[0];
        suffixGCD[n - 1] = nums[n - 1];
        
        for (int i = 1; i < n; ++i) {
            prefixGCD[i] = gcd(prefixGCD[i - 1], static_cast<long long>(nums[i]));
        }
        
        for (int i = n - 2; i >= 0; --i) {
            suffixGCD[i] = gcd(suffixGCD[i + 1], static_cast<long long>(nums[i]));
        }
        
        // Helper function to calculate LCM of two numbers
        auto lcm = [](long long a, long long b) { return (a / gcd(a, b)) * b; };

        // Calculate the initial LCM and GCD for the entire array
        long long totalLCM = nums[0];
        for (int i = 1; i < n; ++i) {
            totalLCM = lcm(totalLCM, nums[i]);
        }
        
        long long totalGCD = prefixGCD[n - 1];
        long long maxFactorScore = totalLCM * totalGCD;

        // Step 2: Calculate maximum factor score by removing each element
        for (int i = 0; i < n; ++i) {
            long long gcdWithoutI = (i == 0) ? suffixGCD[1] : (i == n - 1) ? prefixGCD[n - 2] : gcd(prefixGCD[i - 1], suffixGCD[i + 1]);
            
            long long lcmWithoutI = (i == 0) ? nums[1] : nums[0];
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    lcmWithoutI = lcm(lcmWithoutI, nums[j]);
                }
            }
            
            long long factorScore = gcdWithoutI * lcmWithoutI;
            maxFactorScore = max(maxFactorScore, factorScore);
        }

        return maxFactorScore;
    }
};
