// this is a basic string problem
// using find function and npos
// npos is of type size_t ans it is the greatest possible value of an element
// npos is defined with a value of -1

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<int> hash;
        int ans = 0;
        for(auto i:S){
            if(J.find(i) != string::npos)   //also can write J.find(i) != -1 
                ans++;
        }
        return ans;
    }
};
