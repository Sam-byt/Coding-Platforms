class Solution {
    int t[202][202];
public :
    
    int solve(int i, int j, vector<vector<int>>& triangle){
        if(i == triangle.size())return 0;
        
        if(t[i][j] != -1)return t[i][j];
        
        return t[i][j] = triangle[i][j] + min(solve(i+1,j,triangle),solve(i+1,j+1,triangle));
        
        
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(t,-1,sizeof(t));
        return solve(0,0,triangle);
        
        
        
    }
};
