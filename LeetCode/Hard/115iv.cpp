class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        vector<double>prev(n+1,0);
        
        prev[0] = 1;
        
        for(int i=1; i<=m;i++){
            for(int j=n;j>=0;j--)
                prev[j]= j==0?1:(s[i-1] == t[j-1]?prev[j-1]+prev[j]:prev[j]);
        }
        
        return (int)prev[n];
    }
};
