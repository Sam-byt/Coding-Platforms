// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    int j =0;
    int len =0,maxlen =-1;
    unordered_map<char,int>umap;
        
        for(int i=0;i<s.length();i++){
            
            umap[s[i]]++;
            
            while(umap.size()>k){
                    umap[s[j]]--;
                    if(umap[s[j]] == 0)umap.erase(s[j]);
                    len--;
                    j++;
                }
            
            if(umap.size()<=k){
                len++;
            }
            
            if(umap.size()==k){
                maxlen = max(maxlen,len);
            }
            
            
            
            
        }
        
        if(umap.size()==k)maxlen=max(maxlen,len);
        
        return maxlen;
    
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends
