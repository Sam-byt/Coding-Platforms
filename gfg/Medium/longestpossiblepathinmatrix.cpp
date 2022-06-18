// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
const int INF = -1e5;
class Solution {
private:
    int solve(vector<vector<int>>&matrix, int i, int j, int x, int y, int m , int n){
        
        if(i<0 || i>=m || j<0 || j>=n || matrix[i][j] == 0)return INF;
        
        if(i==x && j==y)return 0;
        
        matrix[i][j] = 0;
        
        int up = solve(matrix,i-1,j,x,y,m,n);
        int down = solve(matrix,i+1,j,x,y,m,n);
        int left = solve(matrix,i,j-1,x,y,m,n);
        int right = solve(matrix,i,j+1,x,y,m,n);
        
        matrix[i][j] = 1;
        
        return 1+max({up,down,left,right});
        
        
        
    }
public:
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here
        if(matrix[xs][ys] == 0 || matrix[xd][yd]==0)return -1;
        else return solve(matrix,xs,ys,xd,yd,matrix.size(), matrix[0].size());
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
