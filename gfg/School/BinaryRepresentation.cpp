// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    string getBinaryRep(int n)
    {
        // Write Your Code here
        string str;
        for(int i=29 ; i>=0 ; i--)str.push_back(((n>>i)&1)+'0');
        return str;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
       
        Solution ob;
        string ans = ob.getBinaryRep(N);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
