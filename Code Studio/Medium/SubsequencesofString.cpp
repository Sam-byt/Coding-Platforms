void solve(string &str, int n,vector<string> &ans, string s)
{
    if(n>=str.size())
    {
        if(s!="")ans.push_back(s);
        return;
    }
    
    
    solve(str, n+1, ans,s);
    
    s= s+str[n];
    
    solve(str, n+1, ans,s);
    
}



vector<string> subsequences(string str){
	
	// Write your code here
    
    vector<string> ans;
    string s;
    int n =0;
    
    solve(str, n, ans,s);
    
    return ans;
	
}
