// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{

    
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    
	    int prev1 = 0, prev2  = 0, curr = 0;
	    
	    for(int i=1; i<=n ; i++)
	    {
	        curr = max(prev1,arr[i-1] + prev2);
	        prev2 = prev1;
	        prev1 = curr;
	    }
	    
	    return prev1;
	    
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
