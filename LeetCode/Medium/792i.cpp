class Solution {
   
private:
    bool isSubsequence( string s1, string s2){
        int i=0, j=0;
        while(i<s1.length() && j<s2.length()){
            if(s1[i] == s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        
        return j==s2.length();
        
    }
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string,bool>umap;
        int ans = 0;
        for(auto & i : words){
            if(umap.find(i) == umap.end()){
                umap[i] = isSubsequence(s,i);
            }
            ans += umap[i];
        }
        return ans;
    }
};
