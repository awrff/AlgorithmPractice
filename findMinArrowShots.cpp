class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0) return 0;
        // 按照右边界升序排列，靠右的箭能够射爆当前气球的同时尽可能射到后面的
        sort(points.begin(), points.end(), [](vector<int>& p1, vector<int>& p2){
            return p1[1] < p2[1];
        });
        int pos = points[0][1];
        int ret = 1;
        for(int i=1; i<points.size(); i++){
            if(points[i][0] > pos){
                // 当前箭无法射中，更新pos
                ++ret;
                pos = points[i][1];
            }
        }
        return ret;
    }
};