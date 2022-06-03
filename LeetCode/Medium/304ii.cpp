class NumMatrix {
public:
    int dp[201][201];
    NumMatrix(vector<vector<int>>& matrix) {
        memset(dp,0,sizeof(dp));
        for(int i=0; i<matrix.size() ; i++){
            for(int j=0; j<matrix[0].size(); j++){
                dp[i+1][j+1] = matrix[i][j] + dp[i+1][j] + dp[i][j+1] - dp[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1] - dp[row1][col2+1] - dp[row2+1][col1] + dp[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
