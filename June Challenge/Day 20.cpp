class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact (n,1);
        for(int i=1; i<n; ++i)
            fact[i] = fact[i-1]*i;
        
        vector<char> v;
        for(int i=1; i<=n; ++i)
            v.push_back(char(i+'0'));   
        
        string ans = "";
        k--;

        while(v.size()!=0) {
            n=v.size();
            int prev=k/(fact[n-1]);
            ans=ans+v[prev];
            v.erase(v.begin()+prev);
            k=k-(prev)*fact[n-1];
        }
        return ans;
    }
};
