// from LeetCode
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        cin.tie(nullptr)->sync_with_stdio(false);

        int least = 1e9 + 7;
        int profit_all = 0, profit_today = 0;
        for (int i = 0; i < prices.size(); i++) {
            least = min(least, prices[i]);
            profit_today = prices[i] - least;
            profit_all = max(profit_all, profit_today);
        }
        return profit_all;
    }
};