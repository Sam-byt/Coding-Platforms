// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    
private:
    
    void solve(string s,string S, vector<string> &ans)
    {
        if(S.length()==0){
            ans.push_back(s);
            return;
        }
        
        string str1 = s;
        string str2 = s;
        
        str1.push_back(' ');
        str1.push_back(S[0]);
        str2.push_back(S[0]);
        
        
        S.erase(S.begin());//reducing the length
        
        solve(str1,S,ans);
        solve(str2,S,ans);
        
    }
    
public:

    vector<string> permutation(string S){
        // Code Here
        string s;
        
        vector<string> ans;
        
        s.push_back(S[0]);
        
        
        S.erase(S.begin());
        
        
        
        solve(s,S,ans);
        
        return ans;
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends
