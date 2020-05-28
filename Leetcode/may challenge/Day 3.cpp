// This is a hashing problem
// Store all the chars and their frequencies in a map and then
// check with all the chars in ransomNote

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        unordered_map<char,int> map;
        for(auto i: magazine)
            map[i]++;
        for(auto i: ransomNote){
            if(map.find(i) == map.end())
                return false;
            else if(map[i] == 0)
                return false;
            else
                --map[i];
        }
        return true;
        
    }
};
