class Solution {
private:
    int t[100002][2][3];
    int solve(int i, bool buy, int max_txn, vector<int>prices){
        
        if(max_txn == 0)return 0;
        if(i == prices.size())return 0;
        
        if(t[i][buy][max_txn] != -1)return t[i][buy][max_txn];
        
        int profit = 0;
            
        if(buy){
            profit = max(-prices[i]+solve(i+1,false,max_txn,prices),solve(i+1,true,max_txn,prices)); 
        }
        else{
            profit = max(prices[i]+solve(i+1,true,max_txn - 1,prices),solve(i+1,false,max_txn,prices));
        }
        
        return t[i][buy][max_txn] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        
        memset(t,-1,sizeof(t));
        return solve(0,true,2,prices);
        
    }
};
