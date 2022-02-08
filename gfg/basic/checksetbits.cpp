// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
   
class Solution{
public:
    int isBitSet(int N){
        for(int i = 1;i<30;i++){
            if((1<<i)-1 == N)return true;
        }
        return false;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isBitSet(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends
