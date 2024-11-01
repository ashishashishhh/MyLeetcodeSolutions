
#include <string>
#include <vector>

class Solution {
public:
    int lengthAfterTransformations(string& s, int t) {
       const long long MOD = 1000000007;  // Use long long for MOD to prevent overflow in calculations
        
        long long current_length = s.size();
        
        // Use a vector to count occurrences of each character
        vector<long long> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        // Perform t transformations
        for (int i = 0; i < t; ++i) {
            long long additional_length = 0;
            vector<long long> new_count(26, 0);

            // Calculate the length changes
            for (int j = 0; j < 26; ++j) {
                if (j == 25) { // if 'z'
                    additional_length = (additional_length + count[j]) % MOD; // Each 'z' becomes "ab" (adds 1 more)
                    new_count[0] = (new_count[0] + count[j]) % MOD; // 'a' count increases
                    new_count[1] = (new_count[1] + count[j]) % MOD; // 'b' count increases
                } else {
                    new_count[j + 1] = (new_count[j + 1] + count[j]) % MOD; // Other letters shift to the next
                }
            }

            // Update current length
            current_length = (current_length + additional_length) % MOD;

            // Update count for the next iteration
            count = new_count;
        }
        
        return current_length;
    }
};
