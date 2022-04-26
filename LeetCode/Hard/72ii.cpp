class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int t[502][502] = {0};
        int m = word1.length(), n = word2.length();
        for(int i=0;i<=m;i++)t[i][0] = i;
        for(int i=0;i<=n;i++)t[0][i] = i;
        
        for(int i=1; i<=m; i++){
            for(int j=1;j<=n;j++){
                //Explore all ways
                if(word1[i-1] == word2[j-1])
                    t[i][j] = t[i-1][j-1];
                else{
                    int insertion = 1 + t[i][j-1];
                    int deletion = 1 + t[i-1][j];
                    int replacement = 1 + t[i-1][j-1];

                    t[i][j] = min(min(insertion,deletion),replacement);
                }
            }        
        }
        
        return t[m][n];
        
        
    }
};
