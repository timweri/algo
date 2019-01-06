#include <algorithm>

class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0, high = height.size() - 1;
        int maxvol = 0;
        while (low < high) {
            int minheight = min(height[high], height[low]);
            int curvol = minheight * (high - low);
            if (curvol > maxvol) {
                maxvol = curvol;
            }
            // move the shorter one
            if (height[low] < height[high]) {
                ++low;
            }
            else if (height[low] > height[high]) {
                --high;
            }
            else {
                ++low;
                --high;
            }
        }
        return maxvol;
    }
};
