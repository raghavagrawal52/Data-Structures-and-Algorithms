class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t count = sizeof(n)*8 -1;
        uint32_t reverse_n = n;
        n >>= 1;
        
        while(n) {
            reverse_n <<= 1;
            reverse_n |= n & 1;
            n >>= 1;
            --count;
        }
        
        reverse_n <<= count;
    
        return reverse_n;
    }
};
