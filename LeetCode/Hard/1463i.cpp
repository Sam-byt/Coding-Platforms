class Solution {
int t[72][72][72];
private:
    int solve(int i, int j1, int j2, int m, int n, vector<vector<int>>grid){
        
        // Column Out of Bound
        if(j1<0 || j1 >= n || j2<0 || j2>=n)return -1e7;
        
        //Row ending
        if(i == m)return 0;
        
        if(t[i][j1][j2] != -1)return t[i][j1][j2];
        
        int ans = 0;
        
        //Explore all paths for Robot1 and 2 simultaneosly
        
        for(int dj1 = -1 ; dj1<= 1; dj1++){
            for(int dj2 = -1; dj2<=1 ; dj2++){
                if(j1 == j2){
                    ans = max(ans, grid[i][j1] + solve(i+1,j1+dj1,j2+dj2,m,n,grid));
                }
                else{
                    ans = max(ans, grid[i][j1] + grid[i][j2] + solve(i+1,j1 + dj1 , j2+dj2, m, n,grid));
                }
                
            }
        }
        
        return t[i][j1][j2] = ans;
        
        
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        memset(t,-1,sizeof(t));
        int m = grid.size(), n = grid[0].size();
        
        return solve(0,0,n-1,m,n,grid);
        
    }
};
