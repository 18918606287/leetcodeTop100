class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        int num1 = 1;
        int num2 = 2;
        for(int i = 2; i < n; i++){
            int tmp = num2;
            num2 = num1 + num2;
            num1 = tmp;
        }
        return num2;
    }
};
