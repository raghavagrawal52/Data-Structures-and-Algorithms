class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = 1 << nums.size(); // for 2^n total subsets
        for(int i = 0; i < n; i++){
            vector<int> temp;
            for(int j = 0; j < nums.size(); j++){
                if((1 << j) & i){
                    temp.push_back(nums[j]);
                }
            }
            res.push_back(std::move(temp));
        }
        return res;
    }
}; 
