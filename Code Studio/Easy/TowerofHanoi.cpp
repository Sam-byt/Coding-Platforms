void solve(int n,int s, int d, int a,vector<vector<int>>&ans)
{
    
    if(n == 1){
        ans.insert(ans.end(),{s,d});
        return;
    }
    
    solve(n-1,s,a,d,ans);
    ans.insert(ans.end(),{s,d});

    
    
    solve(n-1,a,d,s,ans);
    
}

vector<vector<int>> towerOfHanoi(int n)
{
    //    Write your code here.
    vector<vector<int>>ans;
    vector<int>v;
    int s = 1, a = 2, d  =3; 
    solve(n,s,d,a,ans);
    return ans;
}
