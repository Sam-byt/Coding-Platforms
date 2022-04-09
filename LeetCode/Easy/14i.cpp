class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string str = strs[0];
        
        int j = 0;
        
        string ans = "";
        
        for(auto i:str){
            for(auto s:strs){
                if(s[j] == i)continue;
                else{
                    return ans;
                }
            }
            ans.push_back(i);
            j++;
        }
        
        return ans;
        
    }
};
