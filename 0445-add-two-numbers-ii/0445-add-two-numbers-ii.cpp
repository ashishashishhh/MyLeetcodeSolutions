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
    ListNode* reverse(ListNode* l1){
        ListNode* prev = nullptr;
        ListNode* curr = l1;
        ListNode* nextt = l1;
        while(curr!=nullptr){
            nextt = curr->next;
            curr->next = prev;
            prev=curr;
            curr = nextt;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        ListNode* l1 = reverse(head1);
        ListNode* l2 = reverse(head2);

       
        int rem = 0;
        ListNode* temp = new ListNode(0);
        ListNode* ans = temp;
        while(l1!=nullptr && l2!=nullptr){
            int x = l1->val + l2->val + rem;
            ListNode* y = new ListNode(x%10);
            rem = x>=10?1:0;
            ans->next = y;
            ans=ans->next;
            l1=l1->next;
            l2=l2->next;

        }
        while(l1!=nullptr){
            int x = l1->val + rem;
            ListNode* y = new ListNode(x%10);
            rem = x>=10?1:0;
            ans->next = y;
            ans=ans->next;
            l1=l1->next;
        }
        while(l2!=nullptr){
        int x =  l2->val + rem;
        ListNode* y = new ListNode(x%10);
        rem = x>=10?1:0;
        ans->next = y;
        ans=ans->next;
        l2=l2->next;

        }
        if(rem!=0){
            ListNode* y = new ListNode(rem);
            ans->next = y;
            ans=ans->next;
        }
        ListNode* ff = reverse(temp->next);
        return ff;



    }
};