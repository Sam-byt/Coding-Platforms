class Solution {
        
    
public:
    int change(int amount, vector<int>& coins) {
        int t[302][5002];
        int n = coins.size();
        for(int i=0; i<=n; i++){
            for(int j=0; j<=amount; j++){
                if(j == 0)t[i][j] = 1;
                else t[i][j] = i==0?0:(coins[i-1]<=j?t[i][j-coins[i-1]]+t[i-1][j]:t[i-1][j]);
            }
        }
        
        return t[n][amount];
    }
};
