class Solution {
public:
    /* dp分解一个数为平方数之和 
        dp[i] = dp[i - j*j] + 1;
        即i-j*j的分解数 + 分解为j*j
    */
    int numSquares(int n) {
        vector<int> dp(n+1);
        for(int i=1; i<=n; i++){
            int minV = INT_MAX;
            for(int j=1; j*j<=i; j++){
                minV = min(minV, dp[i - j*j]);
            }
            dp[i] = minV + 1;
        }
        return dp[n];
    }
};