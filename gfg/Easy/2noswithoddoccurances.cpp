// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<int> twoOddNum(int Arr[], int N)  
    {
        // code here
        int Xor = 0;
        for(int i=0;i<N;i++)Xor = Xor^Arr[i];
        
        
        int rightmost_set_bit = Xor & ~(Xor - 1);
        int x = 0, y =0;
        
        for(int i=0;i<N;i++){
            if(Arr[i] & rightmost_set_bit)x = x^Arr[i];
            else y = y^Arr[i];
        }
        
        if(x>y)return {x,y};
        else return {y,x};
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
        int Arr[N];
        for(int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<int>ans=ob.twoOddNum(Arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
