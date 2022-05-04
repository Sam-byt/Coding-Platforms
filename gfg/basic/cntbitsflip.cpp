// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        // Your logic here
        int cnt = 0;
        while(a>0 && b>0){
            
            if((a&1) != (b&1))cnt++;
            
            a>>=1;
            b>>=1;
            
        }
        
        while(a>0){
            if(a&1)cnt++;
            a>>=1;
        }
        
        while(b>0){
            if(b&1)cnt++;
            b>>=1;
        }
        
        return cnt;
    }
};

// { Driver Code Starts.

// Driver Code
int main()
{
	int t;
	cin>>t;// input the testcases
	while(t--) //while testcases exist
	{
		int a,b;
		cin>>a>>b; //input a and b

        Solution ob;
		cout<<ob.countBitsFlip(a, b)<<endl;
	}
	return 0;
}  // } Driver Code Ends
