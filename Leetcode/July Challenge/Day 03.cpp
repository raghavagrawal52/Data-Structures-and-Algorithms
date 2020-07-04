class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        N = N%14 == 0 ? 14: N%14;
        vector<int> prev = cells;
        cells[0] = 0;
        cells[cells.size()-1] = 0;
        for(int i=0; i<N; ++i) {
            for(int j=1; j<prev.size()-1; ++j) {
               if(prev[j-1] == prev[j+1])
                   cells[j] = 1;
                else
                    cells[j] = 0;
            }
            prev  = cells;
        }
        return prev;
    }
};
