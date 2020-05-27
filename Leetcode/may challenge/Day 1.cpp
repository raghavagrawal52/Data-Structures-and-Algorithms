// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// This problem can be solved using binary search
// for first occurence of a number

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n;
        int ans;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isBadVersion(mid)){
                ans = mid;
                high = mid-1;
            }else
                low = mid+1;
        }
        return ans;
    }
};
