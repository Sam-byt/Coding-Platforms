class Solution {
    
int t[101][101] = {0};
private:
    
    int solve(int m, int n)
    {
        
        
        if(m==0 && n==0)return 1;
        
        if(m<0 || n<0)return 0;
        
        if(t[m][n] != -1)return t[m][n];
        
        return t[m][n] = solve(m,n-1) + solve(m-1,n);
              
    }
    
    
public:
    int uniquePaths(int m, int n) {
        
        memset(t,-1,sizeof(t));
        return solve(m-1,n-1);
        
    }
};
