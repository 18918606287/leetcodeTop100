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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        while(lists.size() > 1){
            vector<ListNode*> newLists;
            for(int i = 0; i < lists.size(); i += 2){
                ListNode* l;
                if(i+1 < lists.size()){
                    l = merge2Lists(lists[i], lists[i+1]);
                    newLists.push_back(l);
                } else {
                    newLists.push_back(lists[i]);
                    l = lists[i];
                } 
            }
            lists = newLists;
        }
        return lists[0];
    }
private:
    ListNode* merge2Lists(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* pt1 = l1;
        ListNode* pt2 = l2;
        ListNode* cur = new ListNode(-1);
        ListNode* ret = cur;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
                cur->next = NULL;
            } else{
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
                cur->next = NULL;
            }
        }
        if(l1 != NULL) cur->next = l1;
        else cur->next = l2;
        return ret->next;
    }
};
