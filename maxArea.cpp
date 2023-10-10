class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int ret = 0;
        // 双指针移动短板
        while(left != right){
            ret = max(ret, (right - left) * min(height[left], height[right]));
            if(height[left] < height[right]) left++;
            else right--;
        }
        return ret;
    }
};