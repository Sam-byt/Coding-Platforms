class Solution {
    
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<int>prev(2,0),curr(2,0);
        prev[0] = prev[1] = 0;
        
        for(int i = n-1;i>=0;i--){
            for(int j = 0;j<=1;j++)
                curr[j] = j?max(-prices[i] + prev[0] , prev[1]):max(prices[i] + prev[1],prev[0]);
            prev = curr;
        }
        
        return prev[1];
    }
};
