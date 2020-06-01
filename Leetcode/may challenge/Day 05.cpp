// I came up with two solutions to this problem
// The first is is by storing the frequencies in a hash map
// The second one is by using the concept of finding min and iterating over to find the min

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> m;
        for(auto i:s)
            m[i]++;
        for(int i=0;i<s.length();++i)
            if(m[s[i]] == 1)
                return i;
        return -1;
    }
};

class Solution {
public:
    int firstUniqChar(string s) { 
        pair<int, int> arr[256]; 
  
        for (int i = 0; s[i]; i++) 
        { 
            (arr[s[i]].first)++; 
            arr[s[i]].second = i; 
        } 

        int res = INT_MAX; 
        for (int i = 0; i < 256; i++){  
            if (arr[i].first == 1) 
                res = min(res, arr[i].second); 
        }
        if(res<s.length())
            return res;
        else
            return -1;
    }
};
