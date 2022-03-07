class Solution {
    
private:
    void solve(int n, int k, int i, vector<int>&num)
    {
        if(n == 1)return;
        
        num.erase(num.begin()+((i+k-1)%n));
        
        i = (i+k-1)%n;
        
        solve(n-1,k,i,num);
    }
    
    
    
public:
    int findTheWinner(int n, int k) {
        
        vector<int>num(n);
        
        iota(num.begin(),num.end(),1);
        
        
        solve(n,k,0,num);
        
        return num[0];
        
        
    }
};
