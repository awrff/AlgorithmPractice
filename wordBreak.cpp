class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n1 = s.size();
        int n2 = wordDict.size();
        if(n1 == 0) return true;
        vector<int> dp(n1+1);
        dp[0] = 1;
        for(int i = 1; i<=n1; i++){
            for(int j=0; j<n2; j++){
                int len = wordDict[j].size();
                if(i >= len){ 
                    dp[i] |= dp[i-len] & (s.substr(i-len, len) == wordDict[j]);
                    // cout << "i: " << i << ", target str: " << s.substr(i-len, len) << ", word: " << wordDict[j] << ", dp[i]: " << dp[i] << endl;
                }
            }
        }
        return dp[n1] == 1;
    }
};