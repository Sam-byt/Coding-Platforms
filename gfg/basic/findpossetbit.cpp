// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        // code here
        
        int index = 0;
        
        int cnt =0;
        
        while(N>0){
            
            if(N&1){
                cnt++;
            }
            
            index++;
            
            if(cnt>1)break;
            
            N>>=1;
            
            
        }
        
        return cnt>1 or cnt == 0? -1 : index;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends
