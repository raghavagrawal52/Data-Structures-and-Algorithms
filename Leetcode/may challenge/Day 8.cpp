// This problem can be solved by finding the cross product of the coordinates
// and comparing them

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
    
        for(int i=0;i<coordinates.size()-2;i=i+2){
            int cross[2];
            cross[0] = (coordinates[i+1][0]-coordinates[i][0])*(coordinates[i+2][1]-coordinates[i+1][1]);
            cross[1] = (coordinates[i+1][1]-coordinates[i][1])*(coordinates[i+2][0]-coordinates[i+1][0]);
            if(cross[0] - cross[1] != 0){
                return false;
            }
        }
        return true;
    }
};
