class Solution {
    int t[1002][202];
    int solve(int i,int txn, vector<int>prices){
        
        if(i == prices.size() || txn==0)return 0;
        
        if(t[i][txn] != -1)return t[i][txn];
        
        int profit = 0;
        
        if(!(txn&1)){//Buy Case : Txn no is even
            profit = max(-prices[i]+solve(i+1,txn-1,prices),solve(i+1,txn,prices));
        }
        else{//Sale Case: Txn no is Odd
            profit = max(prices[i]+solve(i+1,txn-1,prices),solve(i+1,txn,prices));
        }
        
        return t[i][txn] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        memset(t,-1,sizeof(t));
        return solve(0,k<<1,prices);
    }
};
