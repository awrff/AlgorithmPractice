#include <string>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算两个数之和
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    string solve(string s, string t) {
        // write code here
        string result = "";
        int sIdx = s.size()-1;
        int tIdx = t.size()-1;
        int extra = 0;
        while(sIdx >= 0 && tIdx >= 0){
            int n1 = s[sIdx] - '0';
            int n2 = t[tIdx] - '0';
            int sum = n1 + n2 + extra;
            result += to_string(sum % 10);
            if(sum >= 10) extra = 1;
            else extra = 0;
            --sIdx;
            --tIdx;
        }
        while(sIdx >= 0){
            int n = s[sIdx] - '0';
            int sum = n + extra;
            result += to_string(sum % 10);
            if(sum >= 10) extra = 1;
            else extra = 0;
            --sIdx;
        }
        while(tIdx >= 0){
            int n = t[tIdx] - '0';
            int sum = n + extra;
            result += to_string(sum % 10);
            if(sum >= 10) extra = 1;
            else extra = 0;
            --tIdx;
        }
        if(extra == 1) result += "1";
        reverse(result.begin(), result.end());
        return result;
    }
};