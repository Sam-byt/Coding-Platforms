// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
private:
    bool isPossible(long t,long N, long M, long L, long H[], long A[]){
        long sum=0,temp;
        for(long i=0; i<N; i++){
            temp = H[i]+A[i]*t;
            if(temp >= L)sum+=temp;
        }
        
        return sum>=M;
    }
public:
    long buzzTime(long N, long M, long L, long H[], long A[])
    {
        // code here
        long  e = 0,temp;
        for(long i=0; i<N; i++){
            temp=ceil((L-H[i])*1.0/A[i]);
            if(temp>e){
                long t = ceil((M-H[i])*1.0/A[i]);
                e = t>temp?t:temp;
            }
        }
        
        long s =0,mid,ans=-1;
        
        while(s<=e){
            mid = s + (e-s)/2;
            isPossible(mid,N,M,L,H,A)?ans = mid, e = mid-1:s = mid+1;
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
