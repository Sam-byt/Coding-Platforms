// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
    private:
    void dfs(int node,int &t, int parent,vector<bool>&visited,vector<int>adj[],vector<int>&disc,vector<int>&low,vector<bool>&ap){
        visited[node] = true;
        disc[node] = low[node] = t++;
        int child =0;
        
        for(auto nbr : adj[node]){
            if(!visited[nbr]){
                dfs(nbr,t,node,visited,adj,disc,low,ap);
                low[node] = min(low[node],low[nbr]);
                
                //Check if articulation point
                if(low[nbr]>=disc[node] && parent!=-1)ap[node] = true;
                child++;
            }
            else{
                //Parent-Case: Ignore
                if(nbr == parent)continue;
                //Back-Edge:
                else low[node] = min(low[node],disc[nbr]);
            }
        }
        
        if(parent == -1 && child>1)ap[node] = true;
        
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int>disc(V,-1),low(V,-1),res;
        vector<bool>visited(V,false),ap(V,false);
        
        int t = 0;
        
        for(int i=0;i<V;i++)
            if(!visited[i])dfs(i,t,-1,visited,adj,disc,low,ap);
            
        for(int i=0;i<V;i++)
            if(ap[i])res.push_back(i);
            
        if(res.size()>0)return res;
        else return {-1};
    }
};

// { Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends
