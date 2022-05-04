class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>umap;
        umap['I'] = 1;
        umap['V'] = 5;
        umap['X'] = 10;
        umap['L'] = 50;
        umap['C'] = 100;
        umap['D'] = 500;
        umap['M'] = 1000;
        
        
        int n = s.length();
        int i = n-1;
        
        int sum =0;
        while(i>=0){
            if(i>0){
                if(s[i]=='V' && s[i-1]=='I'){
                    sum+=4;
                    i=i-2;
                }
                else if(s[i]=='X' && s[i-1]=='I'){
                    sum+=9;
                    i=i-2;
                }
                else if(s[i]=='L' && s[i-1]=='X'){
                    sum+=40;
                    i=i-2;
                }
                else if(s[i]=='C' && s[i-1]=='X'){
                    sum+=90;
                    i=i-2;
                }
                else if(s[i]=='D' && s[i-1]=='C'){
                    sum+=400;
                    i=i-2;
                }
                else if(s[i]=='M' && s[i-1]=='C'){
                    sum+=900;
                    i=i-2;
                }
                else{
                    sum+=umap[s[i]];
                    i--;
                }
            }
            if(i==0){
                sum += umap[s[i]];
                i--;
            }
            
        }
        
        return sum;
        
    }
};
