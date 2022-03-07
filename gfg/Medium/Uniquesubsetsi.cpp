// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    private:
    void solve(vector<int> arr, int n,vector<int> v,set<vector<int>>&s)
    {
        if(n<0){
            sort(v.begin(),v.end());
            s.insert(v);
            return;
        }
        
        solve(arr,n-1,v,s);
        
        v.push_back(arr[n]);
        
        solve(arr,n-1,v,s);
    }
    public:
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        vector<vector<int> > ans;
        vector<int> v;
        set<vector<int>>s;
        
        solve(arr,n-1,v,s);
        
        set<vector<int>> :: iterator itr;
        
        for (itr = s.begin(); itr != s.end(); itr++)
        {
            ans.push_back(*itr);
        }
        
        return ans;
        
        
         
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends
