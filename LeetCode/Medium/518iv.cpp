class Solution {
        
    
public:
    int change(int amount, vector<int>& coins) {
        vector<int>prev(amount+1,0);
        prev[0] = 1;
        int n = coins.size();
        for(int i=1; i<=n; i++){
            for(int j=0; j<=amount; j++)
                prev[j] = j==0?1:(coins[i-1]<=j?prev[j-coins[i-1]]+prev[j]:prev[j]);
        }
        
        return prev[amount];
    }
};
