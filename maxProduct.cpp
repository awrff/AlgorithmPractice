class Solution {
public:
    /* 存在正负数两种情况，因此要维护两个数组，一个尽可能大，一个尽可能小
        最大乘积可能来自于：
            1.前一个数结尾的尽可能大的数 * 当前数 （正数情况）
            2.前一个数结尾的尽可能小的数 * 当前数 （负数情况）
            3.当前数 */
    int maxProduct(vector<int>& nums) {
        vector<int> maxValue(nums);
        vector<int> minValue(nums);
        for(int i=1; i<nums.size(); i++){
            maxValue[i] = max(maxValue[i-1] * nums[i], max(nums[i], minValue[i-1] * nums[i]));
            minValue[i] = min(minValue[i-1] * nums[i], min(nums[i], maxValue[i-1] * nums[i]));
        }
        return *max_element(maxValue.begin(), maxValue.end());
    }
};