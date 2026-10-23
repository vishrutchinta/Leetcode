#include <math.h>

double angleClock(int hour, int minutes) {
    double minute_angle = minutes * 6.0;
    double hour_angle = (hour % 12) * 30.0 + minutes * 0.5;
    
    double diff = fabs(hour_angle - minute_angle);
    return diff < (360.0 - diff) ? diff : (360.0 - diff);
}