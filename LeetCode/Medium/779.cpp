class Solution {
    
    
public:
    int kthGrammar(int n, int k) {
        
        
        if(n == 1 && k == 1)return 0;
        
        int mid = (1<<(n-2));
        
        return k<=mid?kthGrammar(n-1,k) : 1 - kthGrammar(n-1,k-mid);
        
    }
};
