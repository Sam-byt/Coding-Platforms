class Solution {

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int t[202][202];
        
        for(int i =0; i<=triangle.size() ; i++)t[triangle.size()][i] = 0;
        
        for(int i = triangle.size()-1 ; i>=0 ; i--){
            for(int j = triangle[i].size()-1; j>=0; j--){
                t[i][j] = triangle[i][j] + min(t[i+1][j],t[i+1][j+1]);
            }
        }
        
        return t[0][0];
        
        
        
        
        
    }
};
