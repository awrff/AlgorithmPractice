#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param a int整型vector 
     * @param n int整型 
     * @param K int整型 
     * @return int整型
     */
    int findKth(vector<int>& a, int n, int K) {
        // write code here
        return fastFindKth(a, 0, n-1, K);
    }
    int fastFindKth(vector<int>& a, int left, int right, int k){
        int key = partition(a, left, right);
        if(key + 1 == k) return a[key];
        else if(key + 1 > k) return fastFindKth(a, left, key-1, k);
        else return fastFindKth(a, key+1, right, k);
    }
    int partition(vector<int>& a, int left, int right){
        int pivot = a[right];
        int i = left;
        for(int j=left; j<right; j++){
            if(a[j] > pivot){
                swap(a[i++], a[j]);
            }
        }
        swap(a[i], a[right]);
        return i;
    }
};