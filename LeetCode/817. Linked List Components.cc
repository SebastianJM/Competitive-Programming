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
    int numComponents(ListNode* head, vector<int>& G) {
        bool freq[10004];
        memset(freq, false, sizeof freq);
        for(int i = 0;i < G.size(); i++)
            freq[G[i]] = true;
        ListNode* a;
        int ans = 0;
        while(head != NULL) {
            a = head -> next;
            if(a != NULL && freq[head -> val] && freq[a -> val])
                ans++;
            head = head -> next;          
        }
        return G.size() - ans;
    }
};