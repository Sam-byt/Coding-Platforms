// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
private:
    
    int solve(int price[], int n,int N,int t[][1001])
    {
        if(n<=0 || N<=0)return 0;
        
        if(t[n][N] != -1)return t[n][N];
        
        if(n<=N)
            return  t[n][N]=max(price[n-1] + solve(price,n,N-n,t), solve(price,n-1,N,t));
        
        if(n>N)return t[n][N] = solve(price,n-1,N,t);
        
    }
    
  public:
    int cutRod(int price[], int n) {
        //code here
        int t[n+1][1001];
        memset(t,-1,sizeof(t));
        return solve(price, n,n,t);
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends
