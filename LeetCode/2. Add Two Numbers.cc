/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans;
        ListNode* head;
        head = ans;
        int x, carry = 0;
        bool first = true;
        while(l1 != NULL || l2 != NULL) {
            x=carry;
            if(l1 != NULL) {
                x += l1 -> val;
                l1 = l1 -> next;
            }                
            if(l2 != NULL) {
                x += l2 -> val;
                l2 = l2 -> next;
            }     
            if(x >= 10) {
                carry = 1;
                x %= 10;
            }
            else
                carry = 0;
            if(first) {
                ans = new ListNode(x);
                head = ans;
                first = false;
            }
            else {
                ans -> next = new ListNode(x);
                ans = ans -> next;
            }       
        }
        if(carry) {
            ans -> next = new ListNode(1);
        }
        return head;
    }
};