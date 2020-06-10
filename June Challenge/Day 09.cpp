class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n == 0) return true;
        if(m == 0) return false;
        
        int j =0;
        for(int i=0;i<m;++i){
            if(t[i] == s[j])
                j++;
        }
        
        if(j == n) return true;
        return false;
    }
};
