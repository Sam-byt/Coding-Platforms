class Solution {

public:
    int maxProfit(vector<int>& prices) {
        

        vector<vector<int>>ahead(2,vector<int>(3,0));
        vector<vector<int>>curr = ahead;
        
        int n = prices.size();
        for(int i=n-1; i>=0; i--){
            for(int j=0;j<=1;j++){
                for(int k=0;k<=2;k++){
                    if(k==0 )curr[j][k] = 0;
                    else{
                        curr[j][k] = j?max(-prices[i]+ahead[0][k],ahead[1][k]):max(prices[i]+ahead[1][k-1],ahead[0][k]);
                    }
                }
            }
            ahead = curr;
        }
        
        return ahead[1][2];
        
    }
};
