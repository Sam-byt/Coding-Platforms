// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
private:
bool isAnagram(int arr1[], int arr2[])
{
    for(int i=0; i<26;i++)
    {
        if(arr1[i]!=arr2[i])return false;
        
    }
    
    return true;
}
public:
	int search(string pat, string txt) {
	    // code here
	    int k = pat.length();
	    
	    int arr[26] = {0};
	    
	    for(auto i : pat)arr[i-97]++;
	    
	    int t[26] = {0};
	    
	    int i=0;
	    
	    for(i=0; i<k-1; i++)t[txt[i] - 97 ]++;
	    
	    int j =0;
	    
	    int cnt =0 ;
	    
	    while(i<txt.length()){
	        
	        t[txt[i] - 97]++;
	        if(isAnagram(arr,t))cnt++;
	        t[txt[j]-97]--;
	        
	        i++;
	        j++;
	        
	    }
	    
	    return cnt;
	    
	    
	    
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
