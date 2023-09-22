class Solution {
public:
    // 未排序数组找最长连续序列，O(n)时间
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> s;
        
        int longest = 0;
        // set记录数字
        for(auto n:nums) s.insert(n);
        for(auto n:nums){
            // 关键在于跳过有前驱数的数字，如果数组中存在4 1 3 2这种序列，只需要从1开始找最长序列，4 3 2在数组中都有前驱数直接跳过
            if(s.find(n-1) != s.end()) continue;
            int start = n;
            int curLen = 0;
            // 从没有前驱数的数字开始寻找
            while(s.find(start) != s.end()){
                 ++curLen;
                 ++start;
            }
            // 更新长度
            longest = max(longest, curLen);
        }
        return longest;
    }
};