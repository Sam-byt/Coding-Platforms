// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long nearestPowerOf2(long long N){
        //code here
        
        // long long ans = 1;
        long long a = N;
        int cnt=0;
        
        while(N>0){
            cnt++;
            N>>=1;
        }
        
        return ((1LL<<cnt)>>1) == a?a:1LL<<cnt;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.nearestPowerOf2(N)<<"\n";
    }
}  // } Driver Code Ends
