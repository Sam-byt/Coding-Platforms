class Solution {
private:
    int t[5002][2];
    int solve(int i, bool buy, vector<int>prices){
        
        if(i>=prices.size())return 0;
        
        if(t[i][buy]!=-1)return t[i][buy];
        
        return t[i][buy]=buy?max(-prices[i]+solve(i+1,false,prices),solve(i+1,true,prices)):max(prices[i]+solve(i+2,true,prices),solve(i+1,false,prices));
            
    }
public:
    int maxProfit(vector<int>& prices) {
        memset(t,-1,sizeof(t));
        return solve(0,true,prices);
    }
};
