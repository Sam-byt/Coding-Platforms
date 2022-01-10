class Solution {
    
    
private:
    void solve(string digits,vector<string> &ans, string s, int i,string mapping[])
    {
        if(i>=digits.length())
        {
            ans.push_back(s);
            return;
        }
        
        
        int index = digits[i] - '0';
        string str = mapping[index];
        
        
        for(auto j:str)
        {
            s = s+j;
            solve(digits,ans,s,i+1,mapping);
            s.pop_back();
        }
        
        
    }
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        string s;
        int i =0;
        if(digits.length()==0)return ans;
        
        string mapping[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        solve(digits,ans,s,i,mapping);
        
        return ans;
        
    }
};
