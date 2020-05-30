// This can be solved by modifying kadane's algorithm
// But can get a bit tricky
// we perform kadane normally and then cal total sum and add kadane to it
// then compare kadane with total sum

class Solution {
public:
    int kadane(vector<int> A, int n){
       int max_so_far = A[0]; 
       int curr_max = A[0]; 
       for (int i = 1; i < n; i++){ 
            curr_max = max(A[i], curr_max+A[i]); 
            max_so_far = max(max_so_far, curr_max); 
       } 
       return max_so_far; 
    }
    int maxSubarraySumCircular(vector<int>& A) {
        if(A.size() == 1) return A[0];
        int n = A.size();
        int max_kadane = kadane(A, n);
        if(max_kadane < 0) return max_kadane;
        int total_sum = 0;
        for (int i=0; i< n; i++){ 
            total_sum += A[i];
            A[i] = -A[i];
        }
        total_sum = total_sum + kadane(A, n);
        return (total_sum > max_kadane ? total_sum : max_kadane);
    }
};
