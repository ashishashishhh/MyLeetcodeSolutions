/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> criticalPts;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        int pos = 0;
        while (curr->next != nullptr) {
            // 1.Traverse and find points
            if (prev != nullptr) {
                // 2.check local min and max and record position
                if ((curr->val > prev->val && curr->val > curr->next->val) ||
                    (curr->val < prev->val && curr->val < curr->next->val)) {
                    criticalPts.push_back(pos);
                }
            }
            prev = curr;
            curr = curr->next;
            pos++;
        }
        if (criticalPts.size() < 2) {
            return {-1, -1};
        }

        // 3. Calculate Distances
        int minDist = INT_MAX;
        int maxDist = criticalPts.back() - criticalPts.front();
        for (int i = 1; i < criticalPts.size(); i++) {
            minDist = min(minDist, criticalPts[i] - criticalPts[i - 1]);
        }

        // return ans
        return {minDist, maxDist};
    }
};