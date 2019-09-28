class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m < n) swap(m,n);
        long long fac_n = 1;
        long long fac_m_n = 1;
        for(long long i = 0; i <= n-2; i++){
            fac_m_n *= (m+i);
            fac_n *= i+1;
        }
        return fac_m_n/fac_n;
    }
};
