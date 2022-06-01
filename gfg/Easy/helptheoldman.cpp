// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
private:
    void solve(int N, int src, int helper, int dest, int &n, vector<int>&ans){
        if(N==1){
            n--;
            if(n==0)ans={src,dest};
            return;
        }
        solve(N-1,src,dest,helper,n,ans);
        n--;
        if(n==0)ans={src,dest};
        solve(N-1,helper,src,dest,n,ans);
    }
public:
    vector<int> shiftPile(int N, int n){
        // code here
        vector<int>ans;
        solve(N,1,2,3,n,ans);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin>>N>>n;
        
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends
