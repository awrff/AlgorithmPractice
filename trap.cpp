class Solution {
public:
    // 接雨水
    int trap(vector<int>& height) {
        int n = height.size();
        // 两个数组记录左右两边最高的墙，maxLeft[i]表示i左边最高的墙的高度
        vector<int> maxLeft(n);
        vector<int> maxRight(n);
        maxLeft[0] = -1;
        for(int i=1; i<n; i++){
            maxLeft[i] = max(maxLeft[i-1], height[i-1]);
        }
        maxRight[n-1] = -1;
        for(int i=n-2; i>=0; i--){
            maxRight[i] = max(maxRight[i+1], height[i+1]);
        }
        int ret = 0;
        // 雨水量 = min(左边最高墙，右边最高墙) - 当前高度
        for(int i=1; i<n-1; i++){
            ret += max(0, min(maxRight[i], maxLeft[i]) - height[i]);
        }
        return ret;
    }
};

// 优化空间，双指针
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxLeft = height[0];
        int maxRight = height[n-1];
        int left = 1;
        int right = n-2;
        int ret = 0;
        // 原理：左右两边相当于同时接，如果maxLeft > maxRight，表示right位置的短板在右边，所以右边一定可以接到maxRight-height[right]的雨水；反之表示left位置的短板在左边
        while(left<=right){
            maxLeft = max(maxLeft, height[left]);
            maxRight = max(maxRight, height[right]);
            if(maxLeft > maxRight){
                ret += maxRight - height[right];
                --right;
            }else{
                ret += maxLeft - height[left];
                ++left;
            }

        }
        return ret;
    }
};