class Solution {
private:
    int t[2002][2002];
    bool solve(string s, string p, int m, int n){
        
        //Base case
        if(m==0 && n==0)return true;
        if(n==0 && m>0)return false;
        if(m==0 && n>0){
            for(int i=0;i<n;i++){
                if(p[i] != '*')return false;
            }
            return true;
        }
        
        if(t[m][n] != -1)return t[m][n];
        
        //Explore and Check
        if(p[n-1] == s[m-1] || p[n-1] == '?')
            return t[m][n] = solve(s,p,m-1,n-1);
        if(p[n-1] == '*')
            return t[m][n] = solve(s,p,m-1,n) || solve(s,p,m,n-1);
        return t[m][n] = false;
    }
public:
    bool isMatch(string s, string p) {
        memset(t,-1,sizeof(t));
        return solve(s,p,s.length(),p.length());
    }
};
