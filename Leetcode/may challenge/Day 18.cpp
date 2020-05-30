class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() == 0 || s2.length() == 0)
            return false;
        
        map<char ,int> A;
        for(int i=0;i<s1.length();++i)
            A[s1[i]]++;
        int l=0;
        int counter = 0;
        
        for(int i=0;i<s2.length();++i){
            char curr = s2.at(i);
            if(A.find(curr) != A.end()){
                A[curr]--;
                if(A[curr] >= 0)
                    counter++;
            }
            if(counter == s1.length())
                return true;
            if(i >= s1.length()-1){
                char lchar = s2.at(l++);
                if(A.find(lchar) != A.end()){
                    if(A[lchar] >=0)
                        counter--;
                    A[lchar]++;
                }
            }
        }
        return false;
        
    }
};
