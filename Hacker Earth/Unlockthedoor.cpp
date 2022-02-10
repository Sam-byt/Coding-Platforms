#include <bits/stdc++.h>
using namespace std;
#define ll long long


const int M = 1e9 + 7;

int binmul(int a, int b){
    int ans = 0;

    while(b>0){
        if(b&1)ans = ((ans % M) + (a%M))%M;
        a = ((a%M)+(a%M))%M;
        b>>=1;
    }

    return ans%M;
}



int binexp(int a, int b){
    int ans = 1;

    while(b>0){
        if(b&1)ans = binmul(ans,a)%M;
        a = binmul(a,a)%M;
        b>>=1;
    }

    return ans%M;
}




int main() {
	// your code goes here
    int fact[100001] = {0};
    fact[0] = 1;

    for(int i=1;i<=100000;i++) {
        fact[i] = (fact[i-1]*1LL*i)%M;
    }

	int t,n,k;
	
	cin>>t;
	
	
	while(t--){

        cin>>k>>n;

        int num = fact[n];

        int den = fact[n-k];

        int ans = (num*1LL*binexp(den,M-2))%M;

        cout<<ans << endl;
	    
	    
	    
	    
	    
	    
	    
	    
	}
	
	
	return 0;
}
