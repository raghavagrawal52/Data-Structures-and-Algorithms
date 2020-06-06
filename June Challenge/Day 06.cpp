// This is a sorting problem 
// Sort in descending order if same then sort second element in ascending order

class Solution {
public:
    static bool compare(vector<int>& a,vector<int>& b){
        return (a[0]>b[0] || (a[0]==b[0] && a[1]<b[1]));
    }
        
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        vector<vector<int>> ans;
        sort(people.begin(), people.end(), compare);
        
        for(int i=0;i<n;++i)
            ans.insert(ans.begin()+people[i][1], people[i]);
        
        return ans;
    }
};
