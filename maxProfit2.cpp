class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        // dp的含义是在第i天不持股和持股情况下自己的资金
        int maxProfit = 0;
        for(int i=1; i<n; i++){
            // 不持股，希望利益最大化，选前一天不持股和前一天持股今天卖出的最大值
            dp[i][0] = max(dp[i-1][0], prices[i] + dp[i-1][1]);
            // 持股，希望剩的钱最多，选前一天持股和今天买入的最大值
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
            maxProfit = max(maxProfit, dp[i][0]);
        }
        return maxProfit;
    }
};