// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

bool f(int *arr, int n){
    for(int i=1; i<n ; i++){
        if(arr[i]  != arr[0])return false;
    }
    return true;
}

vector<int> reaching_height(int n, int a[]) {
    // Complete the function
    if(f(a,n) && n>1)return {-1};
    
    vector<int>ans(n);
    
    sort(a, a+n);
    
    int idx = 0;
    for(int i = n-1;i>=(n/2);i--){
        ans[idx] = a[i];
        idx+=2;
    }
    
    idx = 1;
    
    for(int i = 0;i<(n/2);i++){
        ans[idx] = a[i];
        idx+=2;
    }
    
    return ans;
    
}
