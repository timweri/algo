class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result = vector<int>(nums.size(), 1);
        int tmp = 1;
        // accumulating from left to right
        // tmp will be the product of everything to the left of the current index
        for(int i = 0; i < nums.size(); ++i) {
            result[i] *= tmp;
            tmp *= nums[i];
        }
        tmp = 1;
        // accumulating from right to left
        // tmp will be the product of everything to the right of the current index
        for(int i = nums.size() - 1; i >= 0; --i) {
            result[i] *= tmp;
            tmp *= nums[i];
        }
        return result;
    }
};
