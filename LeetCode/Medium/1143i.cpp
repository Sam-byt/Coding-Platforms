
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int t[1002][1002];
        int m = text1.length(), n = text2.length();
        for(int i=0 ; i<=m ; i++){
            for(int j =0; j<=n ; j++)
                t[i][j] = i == 0 || j==0?0:(text1[i-1] == text2[j-1]?1 + t[i-1][j-1]:max(t[i-1][j],t[i][j-1]));
        }
        
        return t[m][n];
    }
};
