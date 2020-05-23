//This problem can be solved in linear time complexity
// In this problem we find if the vector intersects the other vector
// If it does then we find max of first and min of the second elements
// then we check for the smaller second element of the two vectors

class Solution
{
    bool intersect(vector<int> &A, vector<int> &B)
    {
        // If A is confined in B
        if (A[1] >= B[0] && A[1] <= B[1])
            return true;
        // If B is confined in A
        else if (B[1] >= A[0] && B[1] <= A[1])
            return true;
        return false;
    }

public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<vector<int>> ans;

        int i = 0, j = 0;
        while (i < A.size() && j < B.size())
        {
            //check for intersection and push
            if (intersect(A[i], B[j]))
                ans.push_back({max(A[i][0], B[j][0]), min(A[i][1], B[j][1])});
            // then check for the smaller of second element in both of the vectors
            // then increment the smaller one
            if (A[i][1] < B[j][1])
                i++;
            else
                j++;
        }
        return ans;
    }
};