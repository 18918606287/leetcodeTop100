#include<stdio.h>
#include<iostream>
#include <fstream>
#include<string>
#include<ctype.h>
#include<stdlib.h>
using namespace::std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return NULL;
        ListNode* fast = head->next->next;
        ListNode* slow = head->next;
        while(fast != slow){
            if(fast->next == NULL || fast->next->next == NULL) return NULL;
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = head;
        
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
ListNode* str2list(string& testcase){
	ListNode* head = new ListNode(0);
	ListNode* cur = head;
	int i = 0, j = 0;
	while(j < testcase.length() && testcase[j-1] != ']'){
		if(!isdigit(testcase[j])){
			string sub = testcase.substr(i, j-i);
			i = j+1;
			if(sub != ""){
				cur->next = new ListNode(stoi(sub));
				cur = cur->next;
			}
		}
		j++;
	}
	
	int pos = stoi(testcase.substr(j+1));
	if(head->next == NULL || pos == -1) return head->next;
	ListNode* end = cur; 
	cur = head->next;
	for(int i = 0; i < pos; i++) cur = cur->next;
	end->next = cur;
	return head->next;
}
int test(){
	Solution* ans = new Solution();
	fstream testcases;
    testcases.open("testcases.txt",ios::in);
	
	while(!testcases.eof())
    {
    	string testcase;
        getline(testcases, testcase);
        cout<<testcase<<endl;
        ListNode* head = str2list(testcase);
        ListNode* res = ans->detectCycle(head);
        if(res == NULL) cout<<"there is no circle in this linked list."<<endl;
        else cout<<"value of circle begining node is: "<<res->val<<endl;
        cout<<endl;
    }
    testcases.close();
}

int main(){
	test();
	return 0;
} 
