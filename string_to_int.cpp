class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        int ret = 0;
        int sign = 1;
        int upper = INT_MAX/10;
        int lower = INT_MIN/10;
        while(i < str.length() && str[i] == ' ') i++;
        if (i == str.length()) return 0;
        if( str[i] != '-' && str[i] != '+' && (str[i] > '9' || str[i] < '0')) return 0;
        if(str[i] == '-'){
            sign = -1;
            i++;
        } else if (str[i] == '+') i++;
        while(i < str.length() && str[i] <= '9' && str[i] >= '0'){
            if(sign*ret < lower || (sign*ret == lower && (str[i]-'0') > 7)) return INT_MIN;
            if(sign*ret > upper || (sign*ret == upper && (str[i]-'0') > 7)) return INT_MAX;
            ret = ret*10 + (str[i] - '0');
            i++;
        }
        return sign*ret;
    }
};
