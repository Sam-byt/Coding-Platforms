// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n = nums.size();
	    vector<int>lis(n,1),lds(n,1);
	    for(int i=0;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(nums[j]<nums[i] && 1+lis[j]>lis[i])lis[i] = 1 + lis[j];
	        }
	    }
	    for(int i=n-1;i>=0;i--){
	        for(int j=n-1;j>i;j--){
	            if(nums[j]<nums[i] && 1+lds[j]>lds[i])lds[i] = 1 + lds[j];
	        }
	    }
	    int high = 0;
	    for(int i=0;i<n;i++)high = max(lis[i]+lds[i],high);
	    
	    return high-1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
