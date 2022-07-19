//{ Driver Code Starts
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// } Driver Code Ends
//User function template for C++
#define pbds                                               \
    tree<pair<int, int>, null_type, less<pair<int, int> >, \
         rb_tree_tag, tree_order_statistics_node_update>
class Solution{
public:	
	vector<int> constructLowerArray(int *arr, int n) {
	    // code here
	    vector<int>ans;
	    pbds s;
	    for(int i=n-1;i>=0;i--){
	        if(i == n-1)ans.push_back(0);
	        else{
	            ans.push_back(s.order_of_key({arr[i],i}));
	        }
	        s.insert({arr[i],i});
	    }
	    
	    reverse(ans.begin(),ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.

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
        auto ans = ob.constructLowerArray(arr, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
