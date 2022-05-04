class Solution {
public:
    string longestPalindrome(string s) {
        int max_len = 0, len = 0;
        string ans;
        int n = s.length();
        //Odd case:
        for(int mid = 0; mid<n; mid++){
            for(int i=0;mid-i>=0 && mid+i<n;i++){
                if(s[mid - i] != s[mid + i])break;
                len = 2*i + 1;
                if(len>max_len){
                    max_len = len;
                    ans = s.substr(mid - i,len);
                }
            }
        }
        
        //Even Case: Double Pivot
        for(int mid = 0; mid<n-1 ; mid++){
            for(int i=1; mid-i+1>=0 && mid+i<n; i++){
                if(s[mid-i+1] != s[mid+i])break;
                len = 2*i;
                if(len>max_len){
                    max_len = len;
                    ans = s.substr(mid- i+1,len);
                }
            }
        }
        
        
        return ans;
    }
};
