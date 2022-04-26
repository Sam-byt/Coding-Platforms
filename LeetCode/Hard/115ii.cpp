class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        double dp[1002][1002] ={0};
        
        
        
        for(int i=0; i<=m;i++){
            for(int j=0;j<=n;j++){
                if(j==0)dp[i][j] = 1;
                else{
                    dp[i][j]= i==0?0:(s[i-1] == t[j-1]?dp[i-1][j-1]+dp[i-1][j]:dp[i-1][j]);
                }
            }
        }
        
        return (int)dp[m][n];
    }
};
