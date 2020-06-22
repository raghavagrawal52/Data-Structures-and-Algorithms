static int x = [](){ios::sync_with_stdio(false),cin.tie(NULL); return 0;}();
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int first = 0, second = 0;
        for(int i: nums) {
            first = (first^i) & ~second;
            second = (second^i) & ~first;
        }
        return first;
    }
};
