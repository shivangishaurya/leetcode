class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxp =0;
        int bp=INT_MAX;
        for (int i = 0; i < n; i++) {
            bp=min(bp,prices[i]);
            maxp=max(maxp,prices[i]-bp);
        }
        return maxp;
    }
};