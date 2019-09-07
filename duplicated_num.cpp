using namespace::std;
#include "test_env.h" 
#include "test_env.cpp" 

#define ANSWER_TYPE int
#define PARA_TYPE vector<int>
#define SOLUTION findDuplicate
#define FILENAME "testcases.txt"

#define INPUT_LISTNODE 0
#define INPUT_VECTOR_INT 1

#define RET_LISTNODE 0

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> count(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++){
            if(count[nums[i]] == 1) return nums[i];
            count[nums[i]]++;
        }
        return -1;
    }
};

#if INPUT_VECTOR_INT == 1
template<typename ANS, typename PARA>
PARA tester<ANS, PARA>::test_resolver(string& testname){
	resolvers* res = new resolvers();
	return res->vector_int_resolver(testname);
}
#else
template<typename ANS, typename PARA>
PARA tester<ANS, PARA>::test_resolver(string& testname){
	//your code here
}
#endif

template<typename ANS, typename PARA>
ANS tester<ANS, PARA>::ans_resolver(string& ansname, PARA para){
	return stoi(ansname);
}

template<typename ANS, typename PARA>
ANS solution_temp<ANS, PARA>::solve(PARA parameter){
	Solution* sol = new Solution();
	return sol->SOLUTION(parameter);
}

int main(){
	tester<ANSWER_TYPE, PARA_TYPE> *t = new tester<ANSWER_TYPE, PARA_TYPE>();
	string filename = FILENAME;
	t->test(filename);
}
