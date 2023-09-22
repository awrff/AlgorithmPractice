class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        // 记录i-1时的maxDis，如果i <= lastMaxDis，表示能跳到i-1次数就能跳到i
        int lastMaxDis = 0;
        int maxDis = nums[0];
        int jumpCnt = 0;
        for(int i=1; i<n; i++){
            if(i > lastMaxDis) {
                // 如果i > lastMaxDis，表示还需要多跳一次，并且更新能跳到i位置的最大能跳的距离
                ++jumpCnt;
                lastMaxDis = maxDis;
            }
            maxDis = max(maxDis, i + nums[i]); 
        }
        return jumpCnt;
    }
};