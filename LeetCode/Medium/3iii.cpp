class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int arr[256]={0};
        int i=0,j=0;
        
        int len, maxlen = 0;
        
        while(i<s.length()){
            arr[s[i]]++;
            
            while(arr[s[i]]>1){
                arr[s[j]]--;
                j++;
            }
            
            len  = i-j+1;
            
            maxlen = max(len,maxlen);
            
            i++;
        }
        
        return maxlen;
    }
};
