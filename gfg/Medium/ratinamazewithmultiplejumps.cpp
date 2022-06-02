// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    bool solve(int i, int j, int n, vector<vector<int>>&matrix, vector<vector<int>>&path){
        if(i>=n || j>=n)return false;
        
        
        if(i == n-1 && j== n-1){
            path[i][j] = 1;
            return true;
        }
        
        path[i][j] = 1;
        
        int temp = matrix[i][j];
        
        for(int k=1; k<=temp; k++){
            
            if((solve(i,j+k,n,matrix,path) || solve(i+k,j,n,matrix,path))==true)return true;
        }
        
        path[i][j] = 0;
        return false;
        
        
    }
public:
	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	   // Code here
	   int n = matrix.size();
	   	vector<vector<int>>path(n,vector<int>(n,0));
	   	
	   	if(solve(0,0,n,matrix,path)==true)return path;
	   	else return {{-1}};
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends
