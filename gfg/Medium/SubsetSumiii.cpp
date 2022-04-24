// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{ 
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        
        
        // bool t[102][10002];
        vector<bool>prev(sum+1,false),curr(sum+1);
        prev[0] = true;
        
        int n = arr.size();
        
        for(int i=1; i<n+1 ; i++){
            for(int j=0; j<sum+1; j++){
                if(j == 0)curr[j] = true;
                else{
                    curr[j] = arr[i-1]<=j?prev[j - arr[i-1]] || prev[j] : prev[j];
                }
            }
            prev = curr;
        }
        
        return prev[sum];
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
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
