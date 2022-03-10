void solve(int n, int a,int k, vector<int>&ans)
{
    if(n<=0){
        ans.push_back(n);
        return;
    }
    if(n>0)
    {
       ans.push_back(n);
       solve(n-k,a,k,ans);
        
        ans.push_back(n);
        
    }
    
}


vector<int> printSeries(int n, int k)
{
    // Write your code here
    vector<int>ans;
    
    solve(n,n,k,ans);
    return ans;
}
