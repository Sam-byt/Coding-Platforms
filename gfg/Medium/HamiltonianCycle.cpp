// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    private:
    bool solve(int i, int cnt, vector<vector<int>>adj, int N, vector<bool>&visited){
        if(cnt == N)return true;
        
        visited[i] = true;
        
        for(auto j : adj[i]){
            if(!visited[j]){
                if(solve(j,cnt+1,adj,N,visited))return true;
            }
        }
        
        visited[i] = false;
        
        return false;
    }
    
    public:
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        // code here
        vector<vector<int>>adj(N+1);
        
        for(auto i : Edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        vector<bool>visited(N+1,false);
        
        for(int i=1;i<=N;i++){
            if(!visited[1]){
                if(solve(i,1,adj,N,visited))return true;
            }
        }
        
        return false;
    }
};
 

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}  // } Driver Code Ends
