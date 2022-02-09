#define M 1337
#define K 1140
#define ll long long


class Solution {

private:
    
    int binmultiply(int a, int b){
        
        int ans = 0;
        
        while(b>0){
            
            if(b&1)ans  = (ans%M + a%M)%M;
            
            a = (a%M + a%M) % M;
            
            b>>=1;
        }
        
        return ans%M;
    }
    
    
    int binexp(int a, int b){
        
        if(b==0)return 1;
        
        int ans =  1;
        
        while(b>0){
            
            if(b&1)ans = binmultiply(ans,a)%M;
            
            a = binmultiply(a,a)%M;
            b>>=1;
            
        }
        
        return ans%M;
        
        
    }
    
public:
    int superPow(int a, vector<int>& b) {
        
        
        int s = 0;
        
        for(int i = 0;i<b.size();i++){
            
            s = (((s*10)%K)+(b[i]%K))%K;
        }
        
        
        return binexp(a,s%K)%M; 
        
    }
};
