// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    #define INF INT_MAX-1 //due to overflow

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	        int t[M+1][V+1];
	        
	        for(int i=0;i<V+1;i++)t[0][i] = INF;
	        for(int i=0;i<M+1;i++)t[i][0] = 0;
	        
	        
	        for(int i=1;i<M+1;i++)
	        {
	            for(int j=1; j<V+1; j++)
	            {
	                t[i][j] = coins[i-1]<=j?min(1 + t[i][j - coins[i-1]],t[i-1][j]):t[i-1][j];
	            }
	        }
	        
	        return t[M][V] == INF?-1:t[M][V];
	        
	        
	   // }
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends
