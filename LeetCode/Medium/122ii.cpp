class Solution {
    
public:
    int maxProfit(vector<int>& prices) {
        
        int t[30009][2] ={0};
        int n = prices.size();
        t[n][0] = t[n][1] = 0;
        
        for(int i = n-1;i>=0;i--){
            for(int j = 0;j<=1;j++)
                t[i][j] = j?max(-prices[i] + t[i+1][0] , t[i+1][1]):max(prices[i] + t[i+1][1],t[i+1][0]);
        }
        
        return t[0][1];
    }
};
