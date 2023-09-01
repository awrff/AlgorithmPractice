#include <functional>
#include <queue>
#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param input int整型vector 
     * @param k int整型 
     * @return int整型vector
     */
    vector<int> GetLeastNumbers_Solution(vector<int>& input, int k) {
        // write code here
        if(input.size() == 0 || k == 0) return {};
        priority_queue<int> pq;
        for(auto n: input){
            if(pq.size() < k){
                pq.push(n);
            }else{
                if(pq.top() > n){
                    pq.pop();
                    pq.push(n);
                }
            }
        }
        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
};