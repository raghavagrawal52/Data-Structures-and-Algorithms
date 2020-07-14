class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle_hour = hour*30, angle_min = minutes*6;
        
        angle_hour += minutes*0.5;
        double ans = abs(angle_hour - angle_min);
        if(ans > 180)
            return 360 - ans;
        return ans;
    }
};
