#include<stdio.h>
#include<iostream>
#include <fstream>
#include<string>
#include<ctype.h>
#include<stdlib.h>
#include<vector>
using namespace::std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_sum = nums[0];
        int max_sum_helper = nums[0];
        for(int i = 1; i < n; i++){
            max_sum_helper = max(max_sum_helper, 0) + nums[i];
            max_sum = max(max_sum, max_sum_helper);
        }
        return max_sum;
    }
};

vector<int> str2vec(string& testcase){
	vector<int> ret;
	int i = 0, j = 0;
	while(j < testcase.length() && testcase[j-1] != ']'){
		if(!isdigit(testcase[j]) && testcase[j] != '-'){
			string sub = testcase.substr(i, j-i);
			i = j+1;
			if(sub != "")
				ret.push_back(stoi(sub));
		}
		j++;
	}
	return ret;
}

double test(){
	Solution* ans = new Solution();
	fstream testcases;
    testcases.open("testcases053.txt",ios::in);
    string testcase = "";
    bool flag = false;
    double acc = 0;
    int sum = 0;
    int res = 0;
    while(!testcases.eof()){
    	if(!flag){
    		getline(testcases, testcase);
    		if(testcase == "") continue;
    		vector<int> one_case = str2vec(testcase);
    		res = ans->maxSubArray(one_case);
    		sum++;
		} else {
			string testText = testcase;
			getline(testcases, testcase);
			if(testcase == "") continue;
			if(stoi(testcase) == res){
				acc++;
				cout<<"Accepted!"<<endl;
			} else {
				cout<<"Testcase: "<<testText<<" is a Wrong Answer."<<endl;
				cout<<"Accurate answer is "<<testcase<<" but your answer is "<<res<<endl;
			}
		}
		flag = !flag;
	}
	cout<<"he";
	acc = 1.0*acc/sum;
	cout<<"The accuracy of the algorithm in this testcase set of "<< sum << " tests is "<<(acc*100)<<"% ."<<endl;
	return acc;
    
}

int main(){
	double acc = test();
	return 0;
}
