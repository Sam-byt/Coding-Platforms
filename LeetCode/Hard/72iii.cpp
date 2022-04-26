class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int m = word1.length(), n = word2.length();
        
        vector<int>prev(n+1,0),curr(n+1,0);
        
        for(int i=0;i<=n;i++)prev[i] = i;
        
        for(int i=1; i<=m; i++){
            for(int j=0;j<=n;j++){
                if(j==0)curr[j] = i;
                else{
                    //Explore all ways
                    if(word1[i-1] == word2[j-1])
                        curr[j] = prev[j-1];
                    else{
                        int insertion = curr[j-1];
                        int deletion = prev[j];
                        int replacement = prev[j-1];

                        curr[j] = 1 + min(min(insertion,deletion),replacement);
                    }
                }
            }
            prev = curr;
        }
        
        return prev[n];
        
        
    }
};
