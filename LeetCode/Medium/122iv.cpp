class Solution {
    
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int aheadNotBuy = 0 , aheadBuy= 0, currNotBuy, currBuy;
        
        for(int i = n-1;i>=0;i--){
                currBuy = max(-prices[i] + aheadNotBuy , aheadBuy);
                currNotBuy = max(prices[i] + aheadBuy,aheadNotBuy);
                aheadNotBuy = currNotBuy;
                aheadBuy = currBuy;
        }
        
        return aheadBuy;
    }
};
