class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low = 0, high = citations.size() - 1;
        int N = citations.size();
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(citations[mid] >= N - mid)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return N - low;
    }
};
