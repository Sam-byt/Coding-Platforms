// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here
        int i,sum=0;
        for(i=0; i<K-1; i++)sum += Arr[i];
        
        int h = INT_MIN;
        
        int j =0;
        while(i<N){
            
            sum += Arr[i];
            h = max(h,sum);
            sum -= Arr[j];
            i++;
            j++;
        }
        
        return h;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}   // } Driver Code Ends
