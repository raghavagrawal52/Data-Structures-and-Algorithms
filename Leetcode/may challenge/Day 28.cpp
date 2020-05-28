//This problem is based on whether the number is odd or even
// If even then the number of 1's in n is same as that of n/2
// If it is odd then add 1 to the number of 1's in n/2

class Solution {
public:
    vector<int> countBits(int num) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        vector<int> out;
        out.push_back(0);
        for(int i=1;i<=num;++i){
            if(i%2)
                out.push_back(out[i/2]+1);
            else
                out.push_back(out[i/2]);
        }
        return out;
    }
};
