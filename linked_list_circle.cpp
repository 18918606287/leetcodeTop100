using namespace::std;
#include "test_env.h" 
#include "test_env.cpp" 

#define ANSWER_TYPE ListNode*
#define PARA_TYPE ListNode*
#define SOLUTION detectCycle
#define FILENAME "testcases142.txt"

//Difinition of LinkedList node.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Solution of problem # 142. 
class Solution{
public:
    static ListNode *detectCycle(ListNode *head) {
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

template<typename ANS, typename PARA>
PARA tester<ANS, PARA>::test_resolver(string& testname){
	ListNode* head = new ListNode(0);
	ListNode* cur = head;
	int i = 0, j = 0;
	//find '['
	while(testname[i] != '[') i++;
	i++;
	j = i;
	while(j < testname.length()){
		while(testname[j] == ' ') j++;
		if(!isdigit(testname[j])){
			while(i < j && !isdigit(testname[i])) i++;
			if(i == j) break;
			int sub = stoi(testname.substr(i, j-i));
			cur->next = new ListNode(sub);
			cur = cur->next;
			i = j+1;
			if(testname[j] == ']') break;
		}
		j++;
	}
	int pos = stoi(testname.substr(j+1));
	if(head->next == NULL || pos == -1) return head->next;
	ListNode* end = cur; 
	cur = head->next;
	for(int i = 0; i < pos; i++) cur = cur->next;
	end->next = cur;
	cur = head;
	return head->next;
}

template<typename ANS, typename PARA>
ANS tester<ANS, PARA>::ans_resolver(string& ansname, PARA para){
	if(!isdigit(ansname[0])) return NULL;
	ListNode* head = para;
	int pos = -1;
	pos = stoi(ansname);
	for(int i = 0 ; i < pos; i++){
		if(head == NULL)
			break;
		head = head->next;
	}
	return head;
}

template<typename ANS, typename PARA>
ANS solution_temp<ANS, PARA>::solve(PARA parameter){
	return Solution::SOLUTION(parameter);
}

int main(){
	tester<ANSWER_TYPE, PARA_TYPE> *t = new tester<ANSWER_TYPE, PARA_TYPE>();
	string filename = FILENAME;
	t->test(filename);
}
