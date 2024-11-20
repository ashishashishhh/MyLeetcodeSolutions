// //  TLE

// class Solution {
// public:
//     int helpr(string &s, int k, int a, int b, int c, int curmins, int l, int r){
//         if(a >= k && b>=k && c >= k)
//          return curmins;
//         if(l > r)
//          return INT_MAX;
//         int left = INT_MAX;
//         if(s[l] == 'a')
//          left = helpr(s, k, a+1, b, c, curmins+1, l+1, r);
//         else if(s[l] == 'b')
//          left = helpr(s, k, a, b+1, c, curmins+1, l+1, r);
//         else
//          left = helpr(s, k, a, b, c+1, curmins+1, l+1, r);

//         int right = INT_MAX;
//         if(s[r] == 'a')
//          right = helpr(s, k, a+1, b, c, curmins+1, l, r-1);
//         else if(s[r] == 'b')
//          right = helpr(s, k, a, b+1, c, curmins+1, l, r-1);
//         else
//          right = helpr(s, k, a, b, c+1, curmins+1, l, r-1);

//         return min(left, right);
//     }
//     int takeCharacters(string s, int k) {
//         int res = helpr(s, k, 0, 0, 0, 0, 0, s.size()-1);
//         return res == INT_MAX ? -1 : res;
//     }
// };

class Solution {
public:
    int takeCharacters(string s, int k) {
        if (k == 0) return 0;
        
        vector<int> cntr(3, 0);
        for (char c : s) cntr[c - 'a']++;
        
        for (int i = 0; i < 3; i++) {
            if (cntr[i] < k) return -1;
        }
        
        int n = s.size();
        vector<int> window(3, 0);
        vector<int> need(3);
        for (int i = 0; i < 3; i++) {
            need[i] = cntr[i] - k;
        }
        
        int left = 0, maxLen = 0;
        for (int right = 0; right < n; right++) {
            window[s[right] - 'a']++;
            while (window[0] > need[0] || 
                   window[1] > need[1] || 
                   window[2] > need[2]) {
                window[s[left] - 'a']--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        
        return n - maxLen;
    }
};