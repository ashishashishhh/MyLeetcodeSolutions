// //withour DP
// class Solution {
// public:
//     bool checkValidString(string s) {
//         int openCount = 0;
//         int closeCount = 0;
//         int length = s.length() - 1;
        
//         // Traverse the string from both ends simultaneously
//         for (int i = 0; i <= length; i++) {
//             // Count open parentheses or asterisks
//             if (s[i] == '(' || s[i] == '*') {
//                 openCount++;
//             } else {
//                 openCount--;
//             }
            
//             // Count close parentheses or asterisks
//             if (s[length - i] == ')' || s[length - i] == '*') {
//                 closeCount++;
//             } else {
//                 closeCount--;
//             }
            
//             // If at any point open count or close count goes negative, the string is invalid
//             if (openCount < 0 || closeCount < 0) {
//                 return false;
//             }
//         }
        
//         // If open count and close count are both non-negative, the string is valid
//         return true;
//     }
// };

#include <unordered_map>
#include <string>
using namespace std;

class Solution {
    unordered_map<string, bool> memo;

    bool helper(const string& s, int balance, int index) {
        // Base case: if we've reached the end of the string
        if (index == s.size()) {
            return balance == 0; // The string is valid if there are no unmatched parentheses
        }

        // If balance is negative, we have more closing brackets than opening, which is invalid
        if (balance < 0) return false;

        // Check if this subproblem has already been solved
        string key = to_string(balance) + ":" + to_string(index);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        bool ans = false;
        char c = s[index];

        if (c == '(') {
            ans = helper(s, balance + 1, index + 1); // Treat '(' as an opening parenthesis
        } else if (c == ')') {
            ans = helper(s, balance - 1, index + 1); // Treat ')' as a closing parenthesis
        } else if (c == '*') {
            // Treat '*' as an opening parenthesis, a closing parenthesis, or an empty string
            ans = helper(s, balance + 1, index + 1) // as '('
                || helper(s, balance - 1, index + 1) // as ')'
                || helper(s, balance, index + 1);    // as empty string
        }

        // Store the result in the memoization table
        memo[key] = ans;

        return ans;
    }

public:
    bool checkValidString(string s) {
        return helper(s, 0, 0);
    }
};

