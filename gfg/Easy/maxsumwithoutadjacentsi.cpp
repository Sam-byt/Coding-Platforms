// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
const int M = 1e6+2;
class Solution{
private:

int t[M] = {0};

int solve(int *arr, int n)
{
    if(n <= 0)return 0;
    
    if(t[n] != -1)return t[n];
    
    
    return t[n] = max(solve(arr,n-1),arr[n-1] + solve(arr,n-2));
}
    
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    
	    memset(t,-1,sizeof(t));
	    return solve(arr,n);
	    
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
