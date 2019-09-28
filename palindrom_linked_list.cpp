/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
const int g_init = []()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    return 0;
}();
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre = NULL;
        while(fast != NULL){
            if(fast->next != NULL)
                fast = fast->next->next;
            else break;
            ListNode* tmp = slow;
            slow = slow->next;
            tmp->next = pre;
            pre = tmp;
        }
        if(fast != NULL) slow = slow->next;
        while(slow != NULL){
            if(pre->val != slow->val) return false;
            pre = pre->next;
            slow = slow->next;
        }
        return true;
    }
};
