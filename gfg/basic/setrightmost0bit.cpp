// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int setBit(int N)
    {
        // Write Your Code here
        int a = N;
        
        bool flag = true;
        
        int index = 0;
        
        
        while(a>0){
            if(!(a&1)){
                flag = false;
                break;
            }
            a>>=1;
            index++;
        }
        
        return flag?N:N|(1<<index);
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
        int ans = ob.setBit(N);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
