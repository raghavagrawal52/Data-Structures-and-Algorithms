// This problem can be solved using hashing
// and then iterating over to find element with frequency greater than n/2

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map <int,int> fre;
        for(int i=0;i<nums.size();i++){
            auto itr = fre.find(nums[i]);
            if(itr != fre.end())
                itr->second = itr->second +1;
            else
                fre.insert(pair<int,int>(nums[i],1));
        }
        map<int,int>::iterator itr = fre.begin();
        while(itr!=fre.end()){
            if(itr->second > nums.size()/2)
                return itr->first;
            ++itr;
        }
        return 0;
    }
};
