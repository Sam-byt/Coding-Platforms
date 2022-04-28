class Solution {
    static bool comp(string &s1,string &s2){
        return s1.length()<s2.length();
    }
    bool check(string &s1, string &s2){
        if(s1.length() != s2.length()+1)return false;
        else{
            int i =0, j=0;
            while(i<s1.length()){
                if(s1[i] == s2[j]){
                    i++;
                    j++;
                }
                else{
                    i++;
                }
            }
            
            return i==s1.length() && j==s2.length();
        }
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n = words.size();
        vector<int>dp(n+1,1);
        int high = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(words[i],words[j]) && 1+dp[j]>dp[i])dp[i] = dp[j]+1;
            }
            high = max(high,dp[i]);
        }
        
        return high;
    }
};
