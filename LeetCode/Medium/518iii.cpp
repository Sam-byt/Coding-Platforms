class Solution {
        
    
public:
    int change(int amount, vector<int>& coins) {
        vector<int>prev(amount+1,0),curr(amount+1);
        prev[0] = 1;
        int n = coins.size();
        for(int i=1; i<=n; i++){
            for(int j=0; j<=amount; j++)
                curr[j] = j==0?1:(coins[i-1]<=j?curr[j-coins[i-1]]+prev[j]:prev[j]);
            prev = curr;
        }
        
        return prev[amount];
    }
};
