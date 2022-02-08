// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    string oddEven(string S) {
        // code here
        int arr[27] ={0};
        for(auto i : S)arr[i-96]++;
        
        int x=0,y=0;
        for(int i=1;i<27;i++){
            if(arr[i]>0){
                if((arr[i]&1) && (i&1))x++;
                if(!(arr[i]&1) && !(i&1))y++;
            }
        }
        
        return (x+y)&1?"ODD":"EVEN";
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.oddEven(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends
