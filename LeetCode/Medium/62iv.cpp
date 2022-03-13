class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int N = n + m - 2;
        int r = m -1;
        
        
        double temp = 1;
        
        
        
        for(int i = 1; i<=r  ; i++){
            temp = temp*(N-r+i)/i;
        }
       
        
        return (int)temp;
    }
};
