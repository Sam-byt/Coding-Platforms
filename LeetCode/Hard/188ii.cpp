class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        int t[1002][202] = {0};
        k<<=1;
        for(int i=n; i>=0;i--){
            for(int j=0;j<=k;j++){
                if(i==n || j==0)t[i][j] = 0;
                else{
                    t[i][j] = j&1?max(prices[i]+t[i+1][j-1],t[i+1][j]):max(-prices[i]+t[i+1][j-1],t[i+1][j]);
                }
            }
        }
        
        return t[0][k];
    }
};
