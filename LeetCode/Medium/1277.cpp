class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int dp[302][302] ={0};
        int n = matrix.size(), m = matrix[0].size(), ans =0;
        for(int i=0; i<n; i++){
            for(int j=0;j<m ; j++){
                if(i == 0 || j == 0 )dp[i][j] = matrix[i][j];
                else{
                    if(matrix[i][j] == 1)
                        dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
                }
                ans += dp[i][j];
            }
        }
        
        return ans;
        
    }
};
