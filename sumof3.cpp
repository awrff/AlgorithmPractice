class Solution {
public:
    // 三数之和：排序 + 遍历数组 + 两数之和 + 去重
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {};
        int sz = nums.size();
        vector<vector<int>> results;
        // 排序
        sort(nums.begin(), nums.end());
        for(int i=0; i<sz-2; i++){
            // 有序，后面的均大于nums[i]，不可能和为0
            if(nums[i] > 0) break;
            // 跳过重复元素
            if(i > 0 && nums[i] == nums[i-1]) continue; 
            int left = i+1;
            int right = sz-1;
            // 两数之和套路
            while(left < right){
                if(nums[i] + nums[left] + nums[right] < 0) ++left;
                else if(nums[i] + nums[left] + nums[right] > 0) --right;
                else {
                    // 关键点，添加结果之后，左右两边都需要跳过重复元素
                    results.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left+1]) ++left;
                    while(left < right && nums[right] == nums[right-1]) --right;
                    ++left;
                    --right;
                }
            }
        }
        return results;
    }
};