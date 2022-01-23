// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	     int sum = accumulate(arr, arr + n, 0);

        int s = sum;

        bool t[n + 1][s + 1];
        for (int i = 0; i < s + 1; i++)
            t[0][i] = false;
        for (int i = 0; i < n + 1; i++)
            t[i][0] = true;

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < s + 1; j++)
            {
                t[i][j] = arr[i - 1] <= j ? t[i - 1][j] || t[i - 1][j - arr[i - 1]] : t[i - 1][j];
            }
        }

        int low = INT_MAX;
        
        //checking only last row for validation

        for(int i=0;i<sum+1;i++)
        {
            if(t[n][i] == true)
            {
                if(abs(i - (sum - i))<low)low = abs(2*i - sum);
                else break;
            }
        }
  
    	return low;
	    
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
