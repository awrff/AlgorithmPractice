/* 两个数组记录前缀乘积和后缀乘积 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        vector<int> post(n);
        pre[0] = nums[0];
        post[n-1] = nums[n-1];
        for(int i=1; i<n; i++) pre[i] = pre[i-1] * nums[i];
        for(int i=n-2; i>=0; i--) post[i] = post[i+1] * nums[i];
        vector<int> ret;
        for(int i=0; i<n; i++){
            if(i == 0) ret.push_back(post[i+1]);
            else if(i == n-1) ret.push_back(pre[i-1]);
            else ret.push_back(pre[i-1] * post[i+1]);
        }
        return ret;
    }
};