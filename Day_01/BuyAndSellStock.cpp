class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int curr_profit = 0,max_profit = 0;
        for(int i=1;i<n;i++){
            int profit = prices[i]-prices[i-1];
            curr_profit = max(profit,curr_profit+profit);
            max_profit = max(max_profit,curr_profit);
        }
        return max_profit;
    }
};