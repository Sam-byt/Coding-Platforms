int findWays(vector<int> &num, int tar)
{
    // Write your code here.
	int n =num.size();
        vector<int>prev(tar+1,0),curr(tar+1);
        prev[0]= 1;
        for(int i= 1; i<n+1;i++){
            for(int j=0; j<tar+1 ;j++)
                curr[j] = (j==0)?1:(num[i-1]<=j?prev[j-num[i-1]] + prev[j]:prev[j]);
            prev= curr;
        }
        return prev[tar];
        
}
