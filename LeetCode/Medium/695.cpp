class Solution {
private:
    int solve(int i, int j, vector<vector<int>>& grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] == 0)return 0;
        
        grid[i][j] = 0;
        
        return 1 + solve(i+1,j,grid) + solve(i,j+1,grid) + solve(i-1,j,grid) + solve(i,j-1,grid);
        
        grid[i][j] = 1;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans = max(ans,solve(i,j,grid));
            }
        }
        
        return ans;
    }
};
