// This is done using swapping method 
// Also can be solved using counting the number of 0,1,2

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int j = n-1, start = 0, end = n-1;
        
        while(start <= end){
            if(nums[end] == 2){
                int t = nums[end];
                nums[end] = nums[j];
                nums[j] = t;
                --end;
                --j;
            }
            else if(nums[end] == 0){
                int t = nums[end];
                nums[end] = nums[start];
                nums[start] = t;
                start++;
                
            }
            else
                --end;
        }
    }
};
