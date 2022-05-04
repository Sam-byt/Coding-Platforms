// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:    
    int swapBits(int x, int p1, int p2, int n)
    {
        // Code Here
        int y = x,z = x;
        bool bit_x,bit_y;
        for(int k =0; k<n; k++){
            bit_x = (x>>(p1+k))&1;
            bit_y = (y>>(p2+k))&1;
            
            z = bit_x?(z|(1<<(p2+k))):(z&~(1<<(p2+k)));
            z = bit_y?(z|(1<<(p1+k))):(z&~(1<<(p1+k)));
        }
        
        return z;
    }
};

// { Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,p1,p2,n;
		cin>>x>>p1>>p2>>n;
		Solution obj;
		int res=obj.swapBits(x,p1,p2,n);
		printf("%d\n", res);
	}
    return 0;
}  // } Driver Code Ends
