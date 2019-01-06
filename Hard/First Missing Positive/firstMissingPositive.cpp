#include <utility>

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int max = nums.size();
        for(auto &it:nums) {
            while (it > 0 && it <= max && nums[it - 1] != it) {
                swap(nums[it - 1], it);
            }
        }
        int result = 1;
        for(auto &it:nums) {
            if (it == result) ++result;
            else return result;
        }
        return result;
    }
};
