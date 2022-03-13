class Solution {
    
    
    
public:
    int uniquePaths(int m, int n) {
        
        vector<int>prev(n,0);
        
        
        
        for(int i=0; i<m; i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){    
                curr[j] = j==0 ? 1:curr[j-1] + prev[j];
            }
            prev = curr;
        }

        return prev[n-1];
        
    }
};
