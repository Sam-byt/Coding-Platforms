class Solution {
    
private:
    int lcs(string s,string revs)
    {
        int n =  s.length();
        int m = revs.length();
        
        int t[501][501];
        
        for(int i=0; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                
                if( i==0 ||j==0)t[i][j] = 0;
                
                else if (s[i-1] == revs[j-1]) t[i][j] = 1 + t[i-1][j-1];
                
                else t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
        
        return t[n][m];
        
        
        
        
    }
public:
    int minInsertions(string s) {
        
        string revs  = s;
        reverse(s.begin(),s.end());
        
        
        return s.length() - lcs(s,revs);
    }
};
