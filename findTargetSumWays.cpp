/* 
    数组元素添加+ -号让和等于target
    设添加负号的数和为neg，(sum-neg) + (-neg) = target
    neg = (sum - target) / 2;
    转换为找出若干数让和为neg
 */
// class Solution {
// public:
//     void backTrack(vector<int>& nums, int idx, int sum, int target, int& ret){
//         if(idx == nums.size()){
//             if(sum == target) ++ret;
//             return ;
//         }
//         // cout << "num: " << nums[idx] << ", sum: " << sum << endl;
//         backTrack(nums, idx+1, sum+nums[idx], target, ret);
//         backTrack(nums, idx+1, sum-nums[idx], target, ret);
//     }
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int ret = 0;
//         backTrack(nums, 0, 0, target, ret);
//         return ret;
//     }
// };
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto n:nums) sum+=n;
        if((sum - target) < 0 || (sum - target) & 1) return 0;
        int neg = (sum - target) / 2;
        int sz = nums.size();
        // vector<vector<int>> dp(sz+1, vector<int>(neg+1));
        // dp[0][0] = 1;
        // for(int i=1; i<=sz; i++){
        //     int num = nums[i-1];
        //     for(int j=0; j<=neg; j++){
        //         if(num <= j) 
        //             dp[i][j] = dp[i-1][j-num] + dp[i-1][j];
        //         else 
        //             dp[i][j] = dp[i-1][j]; 
                
        //     }
        // }
        // cout << "ret: " << dp[sz][neg] << endl;
        // return dp[sz][neg];

        vector<int> dp(neg+1);
        dp[0]=1;
        for(int i=1; i<=sz; i++){
            int num = nums[i-1];
            for(int j=neg; j>=num; j--){
                dp[j] = dp[j-num] + dp[j];
            }
        }
        return dp[neg];
    }
};