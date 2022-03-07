class Solution {
private:
    void solve(int index, string s, vector<string> &ans )
    {
        if(index == s.length())
        {
            ans.push_back(s);
            return;
        }
        
        if(isdigit(s[index]))
            solve(index + 1, s, ans); 
        else{
            if(s[index]<'a')
                s[index]+=32;
            
            solve(index+1,s,ans);
            
            if(s[index]>='a')
                s[index]-=32;
                
            solve(index+1,s,ans);
        }
            
    }
    
    
public:
    vector<string> letterCasePermutation(string s) {
        
        vector<string> ans;
        
        solve(0,s,ans);
        
        return ans;
        
    }
};
