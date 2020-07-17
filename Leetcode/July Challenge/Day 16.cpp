class Solution {
public:
    double myPow(double x, long long n) {
        double ans = 1;
        long long t = n;
        if(n < 0) {
            t = -n;
        }
        
        while(t > 0) {
            if(t%2 == 1)
                ans *= x;
            x *= x;
            t /= 2;
        }
        
        if(n<0)
            ans = 1/ans;
        
        return ans;
    }
};
