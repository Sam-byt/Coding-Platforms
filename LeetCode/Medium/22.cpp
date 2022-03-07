class Solution {

private:
    
    void solve(int open, int close, string op, vector<string>&ans )
    {
        if(open == 0 && close == 0){
            ans.push_back(op);
            return;
        }
        
        if(open != 0){
            
            string op1 = op;
            op1.push_back('(');
            solve(open-1,close,op1,ans);
        }
        
        if(close>open)
        {
            string op2 = op;
            op2.push_back(')');
            solve(open,close-1,op2,ans);
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        
        
        
        string s;
        
        vector<string>ans;
        
        solve(n,n,s,ans);
        
        return ans;
        
    }
};
