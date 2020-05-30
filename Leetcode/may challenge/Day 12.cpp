// Since we are given a sorted array we can use binary search
// and then check for various cases
// Bonus : If it was not sorted can be solved in linear time using XOR

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low =0, high = nums.size()-1;
        if(nums.size() ==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        while(low<=high){
            int mid = low + (high-low)/2;
            if((nums[mid] == nums[mid-1]) && (mid%2 ==1))
                low = mid+1;
            else if((nums[mid] == nums[mid-1]) && (mid%2 == 0))
                high = mid-1;
            else if((nums[mid] == nums[mid+1]) && (mid%2 ==1))
                high = mid-1;
            else if((nums[mid] == nums[mid+1]) && (mid%2 == 0))
                low = mid+1;
            else
                return nums[mid];
        }
        return -1;
    }
};
