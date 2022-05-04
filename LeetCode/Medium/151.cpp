class Solution {
public:
    string reverseWords(string s) {
        int i = 0,j = 1;
        while(j<s.length()){
            if(s[j] == ' ' && s[i] == ' '){
                s.erase(s.begin()+j);
            }
            else{
                i++;
                j++;
            }
        }
        if(s[0] == ' ')s.erase(s.begin()+0);
        int n = s.length();
        if(s[n-1] == ' ')s.erase(s.end()-1);
        
        n = s.length();
        
        i=0, j=n-1;
        
        while(i<j){
            swap(s[i++],s[j--]);
        }
        
        i=0,j=0;
        int k;
        while(j<n){
            if(s[j] == ' '){
                k = j-1;
                while(i<k){
                    swap(s[i++],s[k--]);
                }
                i = j+1;
            }
            j++;
        }
        
        k = j-1;
        while(i<k){
            swap(s[i++],s[k--]);
        }
        
        
            
            
        return s;
    }
};
