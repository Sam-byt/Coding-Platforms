// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#define ll long long
class Solution{
public:
    int isPossible(long long S, long long N, long long X, long long A[])
    {
        // code here
        vector<ll>v;
        v.push_back(S);
        ll s=S,sum=S;
        for(int i=0;i<N && sum<=X;i++){
            s+=A[i];
            v.push_back(s);
            sum += s;
            s = sum;
        }
        
        int pos = lower_bound(v.begin(),v.end(),X) - v.begin();
        
        while(pos>=0){
            if(v[pos]<=X)X-=v[pos];
            if(X==0)return true;
            pos--;
        }
        
        return false;
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long S, N, X;
        cin>>S>>N>>X;
        long long A[N];
        for(long long i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        if(ob.isPossible(S, N, X, A))
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}  // } Driver Code Ends
