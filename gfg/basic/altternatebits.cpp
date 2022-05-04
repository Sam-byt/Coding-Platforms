// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int bitsAreInAltOrder(long long int n){
        // code here
        long long int num = n^(n>>1);
        while(num>0){
            if(!(num&1))return false;
            num>>=1;
        }
        
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.bitsAreInAltOrder(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
