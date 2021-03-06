// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
#define ll long long
class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int K)
    {
        //code here
        unordered_map<int,int>umap;
        for(int i=0;i<n;i++){
            umap[A[i]%K]++;
        }
        ll temp = 0,cnt=0;
        for(int i=0;i<n;i++){
            umap[A[i]%K]--;
            temp = (K - (A[i]%K))%K;
            if(umap.find(temp) != umap.end())cnt += umap[temp];
        }
        
        return cnt;
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
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}
  // } Driver Code Ends
