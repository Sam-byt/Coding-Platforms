class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        vector<int>v;
        int m = grid.size(), n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                v.push_back(grid[i][j]);
            }
        }
        
        int s = v.size();
        int index;
        for(int i=0;i<s;i++){
            index = (i+k)%s;
            grid[index/n][index%n] = v[i];
        }
        
        return grid;
        
    }
};
