class Solution {
//     int t[202][202];
//     int solve(int m, int n, vector<vector<int>>grid){
//         if(m == 0 && n == 0)return grid[0][0];
//         if(m<0 || n<0)return INT_MAX;
        
//         if(t[m][n] != -1)return t[m][n];
        
//         return t[m][n] = grid[m][n] + min(solve(m-1,n,grid),solve(m,n-1,grid));
//     }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        // memset(t,-1,sizeof(t));
        // return solve(grid.size()-1, grid[0].size()-1,grid);
        
        int t[202][202];
        
        int m = grid.size(), n = grid[0].size();
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i == 0 && j == 0)t[i][j] = grid[0][0];
                else {
                    if(i == 0)t[i][j] = grid[i][j] + t[i][j-1];
                    else if(j == 0)t[i][j] = grid[i][j] + t[i-1][j];
                    else t[i][j] = grid[i][j] + min(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        return t[m-1][n-1];
        
    }
};
