//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
    int solve(int h, int m, bool flag,vector<vector<int>>&dp){
        if(h<=0 || m<=0)return 0;
        
        if(dp[h][m] != -1)return dp[h][m];
       
        return dp[h][m] = 1 + (flag?solve(h+3,m+2,false,dp):max(solve(h-5,m-10,true,dp),solve(h-20,m+5,true,dp)));
        
    }
    public:
        int maxLevel(int h,int m)
        {
            // code here
            vector<vector<int>>dp(2001,vector<int>(2001,-1));
            return solve(h,m,true,dp)-1;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    Solution a;
    while(t--)
    {
        int h,m;
        cin>>h>>m;
        cout<<a.maxLevel(h,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends
