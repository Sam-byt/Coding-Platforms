//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    private:
    void dfs(int i, vector<vector<int>> &adj,int V, vector<bool>&visited){
        visited[i] = true;
        
        for(int j=0;j<V;j++){
            if(adj[i][j] && !visited[j]){
                dfs(j,adj,V,visited);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<bool>visited(V,false);
        int cnt =0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                cnt++;
                dfs(i,adj,V,visited);
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends
