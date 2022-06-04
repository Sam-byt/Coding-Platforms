class Solution {
private:
    void dfs(int node, int &t,vector<vector<int>>&adj, vector<bool>&visited, vector<int>&disc, vector<int>&low, int parent, vector<vector<int>>&res){
        
        visited[node] = true;
        disc[node] = low[node] = t++;
        
        for(auto nbr : adj[node]){
            if(!visited[nbr]){
                dfs(nbr,t,adj,visited,disc,low,node,res);
                low[node] = min(low[node],low[nbr]);
                
                //check for bridge
                if(low[nbr]>disc[node]){
                    res.push_back({node,nbr});
                }
            }
            else{
                if(nbr == parent)continue; //Parent case:ignore
                else low[node] = min(low[node],disc[nbr]); //Back Edge
            }
        }
        
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto x:connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        vector<vector<int>>res;
        
        vector<int>disc(n,-1),low(n,-1);
        vector<bool>visited(n,false);
        
        int t = 0;
        for(int i=0; i<n ; i++){
            if(!visited[i]){
                dfs(i,t,adj,visited,disc,low,-1,res);
            }
        }
        
        return res;
        
    }
};
