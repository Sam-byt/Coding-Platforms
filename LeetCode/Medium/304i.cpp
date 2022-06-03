class NumMatrix {
public:
    vector<vector<int>>m;
    NumMatrix(vector<vector<int>>& matrix) {
        this->m = matrix;
        int s=0;
        for(int i=0; i<m.size() ; i++){
            s = 0;
            for(int j=m[0].size()-1; j>=0; j--){
                s+= m[i][j];
                m[i][j] = s;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for(int i=row1; i<=row2; i++){
            col2+1<m[0].size()?ans += m[i][col1] - m[i][col2+1]:ans += m[i][col1];
        }
        
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
