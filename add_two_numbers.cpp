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
        int digit = l1->val + l2->val;
        int carry = digit/10;
        ListNode* ret = new ListNode(digit%10);
        ListNode* pt = ret;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 != NULL || l2 != NULL || carry != 0){
            digit = carry;
            if(l1 != NULL){
                digit += l1->val;
                l1 = l1->next;
            } 
            if(l2 != NULL){
                digit += l2->val;
                l2 = l2->next;
            } 
            carry = digit/10;
            pt->next = new ListNode(digit%10);
            pt = pt->next;
        }
        return ret;
    }
};
