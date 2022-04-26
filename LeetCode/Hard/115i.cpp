class Solution {
private:
    int dp[1002][1002];
    int solve(string s,string t, int m, int n){
        if(n==0)return 1;
        if(m==0)return 0;
        if(dp[m][n]!=-1)return dp[m][n];
        return dp[m][n]=s[m-1] == t[n-1]?solve(s,t,m-1,n-1)+solve(s,t,m-1,n):solve(s,t,m-1,n);
    }
public:
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return solve(s,t,s.length(),t.length());
    }
};
