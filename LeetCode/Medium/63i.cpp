class Solution {

int t[101][101] = {0};
    
private:
    
    int solve(int m, int n, vector<vector<int>> obstacleGrid)
    {
        if(m==0 && n==0)return 1;
        
        if(m<0 || n<0 || obstacleGrid[m][n] == 1)return 0;
        
        if(t[m][n] != -1)return t[m][n];
        
        
        return t[m][n] = solve(m,n-1,obstacleGrid) + solve(m-1,n,obstacleGrid);        
        
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        memset(t,-1,sizeof(t));
        
        if(obstacleGrid[0][0] == 1)return 0;
        
        
        return solve(obstacleGrid.size()-1, obstacleGrid[0].size()-1, obstacleGrid);
        
    }
};
