// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int Xor = 0;
        for(auto i:nums)Xor = Xor ^ i;
        int x=0,y=0;
        int rightmost_set_bit_no = Xor & ~(Xor - 1);
        for(auto i:nums){
            if(i & rightmost_set_bit_no)x = x^ i;
            else y = y ^ i;
        }
        
        
       if (x<y)
            return {x,y};
        else return   {y,x};
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends
