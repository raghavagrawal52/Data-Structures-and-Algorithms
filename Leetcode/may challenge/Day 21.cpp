// This is a question on DP
// In this we store the number of valid matrices that can be formed including the number itself
// and keep on incrementing the sum based on the min of the predecessors

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int sum = 0;
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                // To check if the element is zero
                if (matrix[i][j] == 0)
                    continue;
                // If 1 then check if it is a border element
                else if (matrix[i][j] == 1 && (i == 0 || j == 0))
                    sum += 1;
                // otherwise calc the min among the left, top and left-up element
                else
                {
                    int temp = min(matrix[i][j - 1], matrix[i - 1][j]);
                    int minimum = min(matrix[i - 1][j - 1], temp);
                    sum = sum + minimum + 1;
                    matrix[i][j] = minimum + 1;
                }
            }
        }
        return sum;
    }
};

// Here is a concise form of the solution

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        
        int sum = 0;
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                if(i>0 && j>0 && matrix[i][j] == 1)
                    matrix[i][j] = min(matrix[i-1][j-1], min(matrix[i][j-1], matrix[i-1][j])) + 1;
                sum += matrix[i][j];
            }
        }
        return sum;
    }
};
