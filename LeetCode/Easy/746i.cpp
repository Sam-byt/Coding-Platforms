class Solution {
private:
    int t[1005];
    int solve(int i,int n, vector<int>& cost){
        
        
        if(i == n)return 0;
        
        if(t[i] != -1)return t[i];
        
        return t[i] = n-i>=2?cost[i]+min(solve(i+1,n,cost),solve(i+2,n,cost)):cost[i]+solve(i+1,n,cost);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        memset(t,-1,sizeof(t));
        int choice0 = solve(0,cost.size(),cost);
        memset(t,-1,sizeof(t));
        int choice1 = solve(1,cost.size(),cost);
        return min(choice0 , choice1);
    }
};
