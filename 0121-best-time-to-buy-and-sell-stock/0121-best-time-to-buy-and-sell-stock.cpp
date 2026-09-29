class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int buyprice=prices[0];
     int maxprice=0;
     for(int i=1;i<prices.size();i++){
        int currprice=prices[i]-buyprice;
        maxprice= max(maxprice,currprice);
        buyprice=min(buyprice,prices[i]);
     } 
     return maxprice; 
    }
};