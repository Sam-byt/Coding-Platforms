class Solution {
public:
    string minWindow(string s, string t) {
        
        string str = "";
        int minlen = s.length() + 1;      
        
        int j=0;
        
        
        unordered_map<char,int> umap;
        
        for(auto i:t){
            umap[i]++;    
        }
        
        int count = umap.size();
        int start;
        
        
        
        for(int i=0; i<s.length(); i++){
            
            
           
                
                
                
            if(count>0){    
                
                if(umap.find(s[i]) != umap.end()){
                    umap[s[i]]--;
                    if(umap[s[i]] == 0)count--;
                }
            }
            
            
            if(count == 0){
                
                if(i -j +1 < minlen){
                    minlen = i - j + 1;
                    start = j;
                }
                
                 while(count == 0){
                
                if(umap.find(s[j]) != umap.end()){
                    
                    umap[s[j]]++;
                    if(umap[s[j]]>0)count++;
                    if(minlen > i -j +1){
                        minlen = i - j +1;
                        start = j;
                    }
                    
                    
                }
                
                j++;
            }
                                
                
                }
                        
            
            
            
        
        
        }
        
        if(minlen != s.length() + 1)str = s.substr(start,minlen);
        else str = "";

        
        return str;
        
        
        
        
        
        
    }
};
