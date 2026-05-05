class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest = prices[0];
        int maxProf = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            lowest = min(lowest, prices[i]);
            maxProf = max(prices[i] - lowest, maxProf);
        }

        return maxProf;
    }
};