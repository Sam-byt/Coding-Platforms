class Solution {

public:
    int cherryPickup(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        // int t[72][72][72];
        vector<vector<int>>front(n,vector<int>(n,0));
        vector<vector<int>>curr = front;
        
        
        for(int i =m; i>=0; i--){
            for(int j1 = 0; j1<n ; j1++){
                for(int j2 = 0; j2<n ; j2++){
                    if(i == m)curr[j1][j2] = 0;
                    else{
                        int ans = -1e8;
                        for(int dj1 = -1 ; dj1<= 1; dj1++){
                            for(int dj2 = -1; dj2<=1 ; dj2++){
                                int value = 0;
                                value = j1 == j2? grid[i][j1] : grid[i][j1] + grid[i][j2];
                                if(j1+dj1>=0 && j1+dj1<n && j2+dj2>=0 && j2+dj2<n)
                                    value += front[j1+dj1][j2+dj2];
                                else value += -1e8;
                                ans = max(ans,value);

                            }
                        }
                        
                        curr[j1][j2] = ans;
                        
                        
                    }
                }
                
                
            }
            
            front = curr;
        }
        
        // return t[0][0][n-1];
        
        return front[0][n-1];
        
    }
};
