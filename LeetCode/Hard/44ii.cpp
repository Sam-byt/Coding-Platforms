class Solution {

public:
    bool isMatch(string s, string p) {
        
        bool t[2002][2002]={0};
        int m = s.length(), n = p.length();
        t[0][0] = true;
        
        for(int i=1;i<=m;i++)t[0][i] = false;
        
        for(int i=1;i<=n;i++){
            bool flag = true;
            for(int j=0;j<i;j++){
                if(p[j] != '*'){
                    flag = false;
                    break;
                }
            }
            t[i][0] = flag;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //Explore and Check
                if(p[i-1] == s[j-1] || p[i-1] == '?')
                    t[i][j] = t[i-1][j-1];
                else if(p[i-1] == '*')
                    t[i][j] = t[i-1][j] | t[i][j-1];
                else t[i][j] = false;
            }
        }
        
        return t[n][m];
        
    }
};
