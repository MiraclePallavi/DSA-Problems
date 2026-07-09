class Solution {
public:
    int solve(int i, int holding, vector<int>& prices, int fee,
              vector<vector<int>>& dp) {
        if (i == prices.size())
            return 0;

        if (dp[i][holding] != -1)
            return dp[i][holding];

        if (holding == 0) {
            
            int buy = solve(i + 1, 1, prices, fee, dp) - prices[i];
            int skip = solve(i + 1, 0, prices, fee, dp);
            return dp[i][holding] = max(buy, skip);
        } else {
            
            int sell = solve(i + 1, 0, prices, fee, dp) + prices[i] - fee;
            int hold = solve(i + 1, 1, prices, fee, dp);
            return dp[i][holding] = max(sell, hold);
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 0, prices, fee, dp);
    }
};