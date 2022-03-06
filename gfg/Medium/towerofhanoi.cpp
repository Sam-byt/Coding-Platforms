// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
    #define ll long long
    
    private:
    
    void solve(int n, int s, int d, int h, ll &cnt)
    {
        if(n == 1){
            cnt++;
            printf("move disk %d from rod %d to rod %d\n",n,s,d);
            return;
        }
        
        
        solve(n-1,s,h,d,cnt);
        printf("move disk %d from rod %d to rod %d\n",n,s,d);
        cnt++;
        
        solve(n-1,h,d,s,cnt);
    
    }
    
    
    
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    long long toh(int N, int from, int to, int aux) {
        // Your code here
        ll cnt = 0;
        solve(N,from,to,aux,cnt);
        
        return cnt;
    }

};

// { Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}


//Position this line where user code will be pasted.  // } Driver Code Ends
