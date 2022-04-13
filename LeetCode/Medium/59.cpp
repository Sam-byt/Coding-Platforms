class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n);
        for(int i =0;i<n;i++)ans[i].resize(n);
        
        int rowstart = 0,rowend = n-1,columnstart = 0, columnend = n-1;
        
        int k =1;
        
        while(k<=n*n){
            
            for(int  i = columnstart ; i<= columnend && k<= n*n ; i++){
                ans[rowstart][i] = k++;
            }
            
            rowstart++;
            
            for(int i = rowstart ; i<= rowend && k<= n*n ; i++ ){
                ans[i][columnend] = k++;
            }
            
            columnend--;
            
            for(int i = columnend;i>=columnstart && k<= n*n ; i--){
                ans[rowend][i] = k++;
            }
            
            rowend--;
            
            for(int i= rowend ; i>= rowstart && k <= n*n; i--){
                ans[i][columnstart] = k++;
            }
            columnstart++;
            
            
        }
        
        return ans;
        
    }
};
