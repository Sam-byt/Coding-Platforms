// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        vector<vector<int> > ans;
        vector<int> v;
        
        set<vector<int>> s;
        
        int N = (1<<n);
        
        int j ,temp;
        
        for(int i=0; i<N;i++)
        {
            temp =i;
            j = 0;
            
            while(temp>0)
            {
                if(temp&1)v.push_back(arr[j]);
                j++;
                temp >>= 1;
            }
            
            sort(v.begin(),v.end());
            s.insert(v);
            v.clear();
        }
        
        
        set<vector<int>> :: iterator itr;
        
        for(itr = s.begin(); itr != s.end(); itr++)
            ans.push_back(*itr);
            
            
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
