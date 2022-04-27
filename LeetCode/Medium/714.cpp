class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int t[50005][2]={0};
        
        for(int i=n; i>=0;i--){
            for(int j=0;j<=1;j++){
                if(i==n)t[i][j] = 0;
                else t[i][j]=j?max(-prices[i]+t[i+1][0],t[i+1][1]):max(prices[i]-fee+t[i+1][1],t[i+1][0]);;
            }
        }
        
        return t[0][true];
    }
};
