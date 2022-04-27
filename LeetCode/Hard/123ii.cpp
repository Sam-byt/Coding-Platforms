class Solution {

public:
    int maxProfit(vector<int>& prices) {
        
       
        
        int t[100002][2][3] = {0};
        
        int n = prices.size();
        for(int i=n; i>=0; i--){
            for(int j=0;j<=1;j++){
                for(int k=0;k<=2;k++){
                    if(k==0 || i==n)t[i][j][k] = 0;
                    else{
                        t[i][j][k] = j?max(-prices[i]+t[i+1][0][k],t[i+1][1][k]):max(prices[i]+t[i+1][1][k-1],t[i+1][0][k]);
                    }
                }
            }
        }
        
        return t[0][1][2];
        
    }
};
