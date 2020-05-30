// This problem can be solved using binary search
// we need to search only upto n/2 because sqrt cannot be greater than n/2

class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 0, high = num/2;
        long int mid;
        if (num == 1) return true;
        while(low<=high){
            mid = low + (high-low)/2;
            if(mid*mid == (long int)num) return true;
            if(mid*mid < (long int)num) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
};
