#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        
        // Helper function to calculate total hours needed at speed k
        auto canEatAll = [&](int k) {
            int hours = 0;
            for (int pile : piles) {
                hours += (pile + k - 1) / k;  // Equivalent to ceil(pile / k)
                if (hours > h) return false;   // Early exit if hours exceed h
            }
            return hours <= h;
        };
        
        // Binary search on the eating speed k
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canEatAll(mid)) {
                right = mid;  // Try to find a smaller k
            } else {
                left = mid + 1;  // Increase k
            }
        }
        
        return left;  // Minimum k where Koko can eat all bananas in h hours
    }
};