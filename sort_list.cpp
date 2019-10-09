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
    ListNode* sortList(ListNode* head) {
        if(!head || head->next == NULL) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre = head;
        while(fast!= NULL && fast->next != NULL){
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = NULL;
        ListNode* front = sortList(head);
        ListNode* back = sortList(slow);
        ListNode* ret = new ListNode(-1);
        ListNode* cur = ret;
        while(front != NULL && back != NULL){
            if(front->val < back->val){
                cur->next = front;
                front = front->next;
            }
            else{
                cur->next = back;
                back = back->next;
            }
            cur = cur->next;
        }
        if(front) cur->next = front;
        if(back) cur->next = back;
        return ret->next;
    }
};
