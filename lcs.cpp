#include <unordered_map>
#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2) {
        // write code here
        int sz1 = str1.size();
        int sz2 = str2.size();
        vector<vector<int>> dp(sz1, vector<int>(sz2));
        vector<vector<int>> len(sz1, vector<int>(sz2));
        int longest = 0;
        int lstI = 0;
        int lstJ = 0;
        for(int i=0; i<sz1; i++) {
            dp[i][0] = str1[i] == str2[0]? 1 : 0;
        }
        for(int i=0; i<sz2; i++){
            dp[0][i] = str1[0] == str2[i]? 1 : 0;
        }
        for(int i=1; i<sz1; i++){
            for(int j=1; j<sz2; j++){
                if(str1[i] != str2[j]){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = dp[i-1][j-1] + 1;
                    if(dp[i][j] > longest){
                        longest = dp[i][j];
                        lstI = i;
                        lstJ = j;
                    }
                }
            }
        }
        string result = "";
        while(lstI >= 0 && lstJ >=0 && str1[lstI] == str2[lstJ]){
            result += str1[lstI];
            --lstI;
            --lstJ;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};