// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

typedef pair<int,int> pi;

class Solution
{
    private:
    bool solve(int i, int j, int m, int n, int k, vector<vector<int>>&grid){
        if(i>=k || i<0 || j>=k || j<0 || grid[i][j]==0)return false;
        
        if(i==m && j==n)return true;
        
        int temp = grid[i][j];
        grid[i][j] = 0;
        
        return solve(i+1,j,m,n,k,grid)||solve(i-1,j,m,n,k,grid)||solve(i,j-1,m,n,k,grid)||solve(i,j+1,m,n,k,grid);
        
        
        
        
        grid[i][j] = temp;
    }
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n = grid.size();
        pi src, dest;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1)src = {i,j};
                if(grid[i][j] == 2)dest = {i,j};
            }
        }
        
        
        return solve(src.first,src.second,dest.first,dest.second,n,grid);
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends
