class Solution {
public:
    static bool cmp(pair<int, int>& a , pair<int, int>& b) {
        return a.second < b.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int>> v;
        vector<int> ans;
        unordered_map<int, int> m;
        
        for(int i:nums)
            ++m[i];
        
        for(auto& it:m)
            v.push_back(it);
        
        sort(v.begin(), v.end(), cmp);
        int i = v.size()-1;
        
        while(k--) {
            ans.push_back(v[i].first);
            --i;
        }
        return ans;
    }
};
