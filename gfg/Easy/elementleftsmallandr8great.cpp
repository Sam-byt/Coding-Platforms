//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends


int findElement(int arr[], int n) {
    vector<int>high(n,0),low(n,0);
    int h = arr[0];
    for(int i=1;i<n;i++){
        high[i] = h;
        h = max(h,arr[i]);
    }
    
    int l = arr[n-1];
    for(int i=n-2; i>=0; i--){
        low[i] = l;
        l = min(l,arr[i]);
    }
    
    for(int i =1; i<n-1; i++){
        if(arr[i]>=high[i] && arr[i]<=low[i]){
            return arr[i];
        }
    }
    
    return -1;
}
