class Solution {
int t[302][5002];
private:
    int solve(int n, int amount, vector<int>coins){
        
        if(n==0 && amount==0)return 1;
        
        if(n==0 && amount>0)return 0;
        
        if(t[n][amount] != -1)return t[n][amount];
        
        return t[n][amount] = coins[n-1]<=amount?solve(n,amount-coins[n-1],coins)+solve(n-1,amount,coins):solve(n-1,amount,coins);
        
        
        
    }
public:
    int change(int amount, vector<int>& coins) {
        memset(t,-1,sizeof(t));
        return solve(coins.size(),amount,coins);
    }
};
