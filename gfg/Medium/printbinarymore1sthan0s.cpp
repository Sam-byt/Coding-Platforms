// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{

private:

    void solve(int n,int i,int j, string op, vector<string> & ans)
    {
        if(i+j==n)
        {
            ans.push_back(op);
            return;
        }
        
        if(i != n){
            string op1 = op;
            op1.push_back('1');
            solve(n,i+1,j,op1,ans);
        }
        
        if(i>j)
        {
            string op2 = op;
            op2.push_back('0');
            solve(n,i,j+1,op2,ans);
        }
        
        
    }
public:	
	vector<string> NBitBinary(int N)
	{
	    // Your code goes here
	    vector<string> ans;
	    
	    
	    solve(N,0,0,"",ans);
	    
	    return ans;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}  // } Driver Code Ends
