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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }
        if(fast == NULL) return head->next;
        ListNode* cur = head;
        while(fast->next != NULL){
            fast = fast->next;
            cur = cur->next;
        }
        cur->next = cur->next->next;
        return head;
    }
};
