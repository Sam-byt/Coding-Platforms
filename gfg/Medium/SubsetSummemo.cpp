// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{  
    
private:
    bool solve(int N, int arr[], int sum, int t[][10001])
    {
        if(sum == 0 && N == 0)return true;
        if(sum > 0 && N == 0)return false;
        
        if(t[N][sum] != -1)return t[N][sum];
        
        
        
        if(arr[N-1]<=sum)
            return t[N][sum] = solve(N-1,arr,sum-arr[N-1],t)||solve(N-1,arr,sum,t);
            
        if(arr[N-1]>sum)
            return t[N][sum] = solve(N-1,arr,sum,t);
        
        
        
        
        
        
        
    }
public:
    bool isSubsetSum(int N, int arr[], int sum){
        // code here 
        
        int t[N+1][10001];
        memset(t,-1,sizeof(t));
        
        // int n = sum;
        solve(N,arr,sum,t);
        
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
