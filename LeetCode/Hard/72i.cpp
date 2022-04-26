class Solution {
private:
    int t[502][502];
    int solve(string word1, string word2, int m, int n){
        
        //base case:
        if(m==0)return n;
        if(n==0)return m;
        
        
        //memoization
        if(t[m][n] != -1)return t[m][n];
        
        //Explore all ways
        if(word1[m-1] == word2[n-1])
            return t[m][n] = solve(word1,word2,m-1,n-1);
        else{
            int insertion = 1 + solve(word1,word2,m,n-1);
            int deletion = 1 + solve(word1,word2,m-1,n);
            int replacement = 1 + solve(word1,word2,m-1,n-1);
            
            return t[m][n] = min(min(insertion,deletion),replacement);
        }
    }
public:
    int minDistance(string word1, string word2) {
        
        memset(t,-1,sizeof(t));
        return solve(word1,word2,word1.length(),word2.length());
    }
};
