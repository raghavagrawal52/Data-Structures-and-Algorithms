class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        
        while(digits[n] == 9) {
            digits[n] = 0;
            --n;
            if(n == -1) {
                digits.insert(digits.begin(), 1);
                return digits;
            }
        }
            
        digits[n] += 1;
        
        while(digits[0] == 0)
            digits.erase(digits.begin());
        
        return digits;
    }
};
