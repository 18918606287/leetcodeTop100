using namespace::std;
#include "test_env.h" 
#include "test_env.cpp" 
#include<vector>

#define ANSWER_TYPE int
#define PARA_TYPE vector<int>
#define SOLUTION findDuplicate
#define FILENAME "testcases.txt"

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

template<typename ANS, typename PARA>
PARA tester<ANS, PARA>::test_resolver(string& testname){
	vector<int> container;
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
			container.push_back(sub);
			i = j+1;
			if(testname[j] == ']') break;
		}
		j++;
	}
	return container;
}

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
