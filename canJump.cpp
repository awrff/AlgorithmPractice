class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxDis = 0;
        for(int i=0; i<n; i++){
            if(i > maxDis) return false;
            maxDis = max(maxDis, i + nums[i]);
        }
        return true;
    }
};