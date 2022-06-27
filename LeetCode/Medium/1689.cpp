class Solution {
public:
    int minPartitions(string n) {
        string s(n.length(),'0');
        int cnt = 0;
        while(n != s){
            for(int i =0; i<n.length(); i++){
                if(n[i]>'0')n[i]-=1;
            }
            cnt++;
        }
        
        return cnt;
    }
};
