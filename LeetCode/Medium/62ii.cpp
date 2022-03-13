class Solution {
    
    
    
public:
    int uniquePaths(int m, int n) {
        
        int t[101][101] = {0};
        
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                t[i][j] = i==0 || j==0? 1:t[i][j-1] + t[i-1][j];
            }
        }

        return t[m-1][n-1];
        
    }
};
