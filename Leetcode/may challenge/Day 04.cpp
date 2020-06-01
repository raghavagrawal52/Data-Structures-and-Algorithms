// This is a basic bit manipulation problem
// first calculate the count of numbers in the binary rep
// then do xor of the number with ones os size of the count

class Solution {
public:
    int findComplement(int num) {
        int count = 0;
        int temp = num;
        while(temp){
            count++;
            temp/=2;
        }
        int ones = pow(2,count)-1;
        int out = num ^ ones;
        return out;
    }
};
