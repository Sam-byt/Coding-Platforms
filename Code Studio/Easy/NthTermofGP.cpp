const int M = 1e9 + 7;
int binexp(int a, int n)
{
    int ans = 1;
    
    while(n>0)
    {
        if(n&1)
            ans = (ans *1LL* a)%M;
        
        
        n>>=1;
        a = (a*1LL*a)%M;
     }
    
    return ans%M;
}
int nthTermOfGP(int N, int A, int R) {
    // Write your code here.
    return (A*1LL*binexp(R,N-1))%M;
    
}

