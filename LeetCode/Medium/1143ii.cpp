
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<int>prev(n+1,0),curr(n+1);
        for(int i=1 ; i<=m ; i++){
            for(int j =0; j<=n ; j++)
                curr[j] = j==0?0:(text1[i-1] == text2[j-1]?1 + prev[j-1]:max(prev[j],curr[j-1]));
            prev = curr;
        }
        
        return prev[n];
    }
};
