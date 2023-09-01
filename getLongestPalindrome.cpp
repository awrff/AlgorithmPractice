#include <algorithm>
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param A string字符串
     * @return int整型
     */
    // 中心扩散
    int getLongestPalindrome(string A) {
        // write code here
        // 中心扩散法
        if (A.size() < 1) return 0;
        int result = 1;
        for (auto i = 0; i < A.size(); i++) {
            result = max(result, getLength(A, i, i));
            if (i != A.size() - 1)
                result = max(result, getLength(A, i, i + 1));
        }
        return result;
    }
    int getLength(string& A, int idx1, int idx2) {
        if (A[idx1] != A[idx2]) return 0;
        int left = idx1 - 1;
        int right = idx2 + 1;
        int result = idx1 == idx2 ? 1 : 2;
        while (left >= 0 && right < A.size() && A[left] == A[right]) {
            result += 2;
            --left;
            ++right;
        }
        return result;
    }
    // manacher 太复杂没写
};