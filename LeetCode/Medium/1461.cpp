class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length()<k)return false;
        vector<bool>visited(1<<k,false);
        
        int n = s.length();
        int i;
        int sum =0;
        for(i =0;i<k-1;i++){
            sum = (sum<<1)+(s[i]-'0');
        }
        
        int j=0;
        while(i<n){
            sum = (sum<<1)+s[i]-'0';
            visited[sum] = true;
            sum = sum - ((s[j]-'0')<<(k-1));
            i++;
            j++;
        }
        
        for(auto p : visited){
            if(p == false)return false;
        }
        
        return true;
    }
};
