/* 和为k的子数组个数 */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int pre = 0;
        int ret = 0;
        // 前缀和+哈希表
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(auto& x: nums){
            // pre[i] - pre[j] = k
            // pre[j] = pre[i] - k
            // 用哈希表记录pre[j]出现次数
            pre += x;
            if(mp.find(pre-k) != mp.end()) {
                ret += mp[pre-k];
            }
            mp[pre]++;
        }
        return ret;
    }
};