class Solution {
public:
    int nthUglyNumber(int n) {
         int p2=0,p3=0,p5=0;
        vector<int> dp;
        dp.push_back(1);
        int i=1;
        while(i<n){
            dp.push_back(min({2*dp[p2],3*dp[p3],5*dp[p5]}));
            if(dp[i]==dp[p2]*2)
                p2++;
            if(dp[i]==dp[p3]*3)
                p3++;
            if(dp[i]==dp[p5]*5)
                p5++;
            i++;
        }
        return dp[n-1];
    }
};
