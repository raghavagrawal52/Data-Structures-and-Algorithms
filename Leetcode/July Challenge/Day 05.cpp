class Solution {
public:
    int hammingDistance(int x, int y) {
        if(x<y) {
            int temp = x;
            x = y;
            y = temp;
        }
        int ans = 0;
        while(x>0) {
            if((x & 1) != (y & 1))
                ++ans;
            x = x >> 1;
            y = y >> 1;
        }
        
        return ans;
    }
};
