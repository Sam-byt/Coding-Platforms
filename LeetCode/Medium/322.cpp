 
#define ll long long
const ll INF = 1e18;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        ll t[13][10001] = {0};
        
        for(int i=0;i<n+1;i++)t[i][0] = 0;
        for(int j=1;j<amount+1;j++)t[0][j] = INF;
        
        for(int i=1; i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                t[i][j] = coins[i-1]<=j? min(1 + t[i][j - coins[i-1]] , t[i-1][j]):t[i-1][j];
            }
        }
        
        return t[n][amount] == INF?-1:t[n][amount];
        
        
    }
};
