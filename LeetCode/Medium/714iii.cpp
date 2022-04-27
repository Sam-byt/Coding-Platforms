class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int aheadBuy =0 ,aheadNotBuy=0,currBuy,currNotBuy;
        
        for(int i=n-1; i>=0;i--){
            currBuy=max(-prices[i]+aheadNotBuy,aheadBuy);
            currNotBuy = max(prices[i]-fee+aheadBuy,aheadNotBuy);
            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }
        
        return aheadBuy;
    }
};
