class Solution {
private:
    bool isValid(int i, int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    
    int solve(int i,int j,int m,int n,vector<vector<int>> board){
        int livecnt = 0;
        if(isValid(i-1,j-1,m,n)){
            if(board[i-1][j-1] == 1)livecnt++;
        }
        if(isValid(i-1,j,m,n)){
            if(board[i-1][j] == 1)livecnt++;
        }
        if(isValid(i-1,j+1,m,n)){
            if(board[i-1][j+1] == 1)livecnt++;
        }
        if(isValid(i,j-1,m,n)){
            if(board[i][j-1] == 1)livecnt++;
        }
        if(isValid(i,j+1,m,n)){
            if(board[i][j+1] == 1)livecnt++;
        }
        if(isValid(i+1,j-1,m,n)){
            if(board[i+1][j-1] == 1)livecnt++;
        }
        if(isValid(i+1,j,m,n)){
            if(board[i+1][j] == 1)livecnt++;
        }
        if(isValid(i+1,j+1,m,n)){
            if(board[i+1][j+1] == 1)livecnt++;
        }
        
        int flag = 0;
        
        if(board[i][j] == 1){
            if(livecnt < 2)flag= 0;
            else if(livecnt == 2 or livecnt == 3)flag = 1;
            else if(livecnt > 3)flag = 0;
        }
        else{
            if(livecnt == 3)flag = 1;
        }
        
        return flag;
     }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>>temp = board;
        
        for(int i =0; i<m; i++){
            for(int j=0;j<n;j++){
                 temp[i][j] = solve(i,j,m,n,board);            
            }
        }
        
        board = temp;
        
        
    }
};
