class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp =0;
        int bp=INT_MAX;
        for (int price:prices) {
            bp=min(bp,price);
            maxp=max(maxp,price-bp);
        }
        return maxp;
    }
};