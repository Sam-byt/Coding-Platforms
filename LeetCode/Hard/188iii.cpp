class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        k<<=1;
        vector<int>ahead(k+1,0),curr(k+1,0);
        for(int i=n-1; i>=0;i--){
            for(int j=0;j<=k;j++){
                if(j==0)curr[j] = 0;
                else{
                    curr[j] = j&1?max(prices[i]+ahead[j-1],ahead[j]):max(-prices[i]+ahead[j-1],ahead[j]);
                }
            }
            ahead =curr;
        }
        
        return ahead[k];
    }
};
