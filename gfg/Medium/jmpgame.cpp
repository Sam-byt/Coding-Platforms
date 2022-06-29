// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    bool solve(int i,int *arr, int n){
        if(i==n-1)return true;
        
        for(int k=1; k<=arr[i]; k++){
            if(solve(i+k,arr,n))return true;
        }
        
        return false;
    }
    
  public:
    int canReach(int A[], int N) {
        // code here
        return solve(0,A,N);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends
