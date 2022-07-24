//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        vector<int>left(n,0),right(n,0);
        int h = arr[0];
        for(int i=1;i<n;i++){
            if(h>=arr[i])left[i]=h;
            h = max(h,arr[i]);
        }
        h = arr[n-1];
        for(int i=n-2;i>=0;i--){
            if(h>=arr[i])right[i] = h;
            h = max(h,arr[i]);
        }
        long long ans = 0;
        for(int i=0;i<n;i++){
            int temp = min(left[i],right[i]);
            if(temp>0)ans += temp - arr[i];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends
