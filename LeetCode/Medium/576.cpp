const int M = 1e9 + 7;
class Solution {
private:
int t[51][51][51];
int solve(int i, int j, int m, int n, int cnt){
    if(i==m || j==n || i<0 || j<0)return 1;
    if(cnt == 0)return 0;
    
    if(t[i][j][cnt] != -1)return t[i][j][cnt];
    
    return t[i][j][cnt] = ((solve(i-1,j,m,n,cnt-1)%M+
        solve(i,j-1,m,n,cnt-1)%M)%M+
        (solve(i+1,j,m,n,cnt-1)%M+
        solve(i,j+1,m,n,cnt-1)%M)%M)%M;
    
}
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(t,-1,sizeof(t));
        return solve(startRow,startColumn,m,n,maxMove)%M;
    }
};
