class Solution {
private:
         
    bool isSafe(int row, int col, vector<string>board, int n)
    {
        int duprow = row;
        int dupcol = col;
        
        while(row>=0 && col>=0)
        {
            if(board[row][col] == 'Q')return false;
            row--;
            col--;
        }
        
        row = duprow;
        col =dupcol;
        
        
        while(col>=0){
            if(board[row][col] == 'Q')return false;
            col--;
        }
        
        col = dupcol;
        
        while(row<n && col>=0)
        {
            if(board[row][col] == 'Q')return false;
            row++;
            col--;
        }
        
        return true;
    }
    
    
    
    void solve(int col,int n, vector<string>&v, vector<vector<string>>&ans)
    {
        if(col == n){
            ans.push_back(v);
            return;
        }
        
        for(int row = 0; row<n ; row++)
        {
            if(isSafe(row,col,v,n))
            {
                v[row][col] = 'Q';
                solve(col+1,n,v,ans);
                v[row][col] = '.';
            }
        }
    }
    
    
public:
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>v(n);
        
        string s(n,'.');
        
        for(int i=0;i<n;i++)v[i] = s;
        
        solve(0,n,v,ans);
        
        return ans.size();
    }
};
