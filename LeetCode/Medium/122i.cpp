class Solution {
    int t[10005][2];
private:
    int solve(int i, bool buy, vector<int>prices){
        if(i==prices.size())return 0;
        
        if(t[i][buy] != -1)return t[i][buy];
        int profit=0;
        if(buy){
            profit = max( - prices[i] + solve(i+1,false,prices),solve(i+1,true,prices));
        }
        else{
            profit = max(prices[i] + solve(i+1,true,prices) , solve(i+1,false,prices));
        }
        
        return t[i][buy] = profit;
        
    }
public:
    int maxProfit(vector<int>& prices) {
        memset(t,-1,sizeof(t));
        return solve(0,true,prices);
    }
};
