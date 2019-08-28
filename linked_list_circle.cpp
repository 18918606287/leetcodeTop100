#include<stdio.h>
#include<iostream>
#include <fstream>
#include<string>
#include<ctype.h>
#include<stdlib.h>
using namespace::std;

//Difinition of LinkedList node.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Solution of problem # 142. 
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

//input and output of my own testcases in file 'testcases142.txt'
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
double test(){
	Solution* ans = new Solution();
	fstream testcases;
    testcases.open("testcases142.txt",ios::in);
    ListNode* head = NULL;
    bool flag = false;
    string testcase = "";
    int acc = 0;
    int sum = 0;
    ListNode* curRes = NULL;
	while(!testcases.eof())
    {
        if(!flag){
        	getline(testcases, testcase);
        	if(testcase == "") continue;
        	//cout<<testcase<<endl;
        	head = str2list(testcase);
        	ListNode* res = ans->detectCycle(head);
        	//if(res == NULL) cout<<"there is no circle in this linked list."<<endl;
        	//else cout<<"value of circle begining node is: "<<res->val<<endl;
        	curRes = res;
        	sum++;
        	flag = !flag;
		} else {
			int pos = -1;
			string testText = testcase;
			getline(testcases, testcase);
			if(testcase == "") continue;
			if(testcase == "NULL")
				head = NULL;
			else{
				pos = stoi(testcase);
				for(int i = 0 ; i < pos; i++){
					if(head == NULL){
						cout<<"testcase: "<<testText<<" is a wrong answer."<<endl;
						break;
					}
					head = head->next;
				}
			}
			
			if(head == curRes){
				acc++;
				cout<<"Accepted!"<<endl;
			} else{
				cout<<"testcase: "<<testText<<" is a wrong answer."<<endl;
				if(pos == -1)
					cout<<"accurate answer is position NULL but your answer is the node of value "<< curRes->val<<endl;
				else
					cout<<"accurate answer is position "<<pos<<" but your answer is the node of value "<< curRes->val<<endl;
			}
			//cout<<endl;
			curRes = NULL;
			flag = !flag;
		}
    }
    testcases.close();
    delete curRes;
    delete head;
    cout<<"The accuracy of the algorithm in this testcase set of "<< sum << " tests is "<<(acc*100)<<"% ."<<endl;
    return 1.0*acc/sum;
}

int main(){
	double acc = test();
	
	return 0;
} 
