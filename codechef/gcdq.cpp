#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define     FastIO      ios_base::sync_with_stdio(0),cin.tie(0)



int main(){
    
    FastIO;

    int t;
    cin >> t;
    
    int n,q,l,r;


    int arr[100001]={0};
    int gcdl[100001]={0};
    int gcdr[100001]={0};
    
    while (t--)
    {
        /* code */
        cin>>n>>q;
        
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            
        }
        
        gcdl[1] = arr[1];
        
        for(int i=2;i<=n;i++){
            gcdl[i] = __gcd(gcdl[i-1],arr[i]);
            }
            
        gcdr[n] = arr[n];
        
        for(int i=n-1;i>=1;i--){
            gcdr[i] = __gcd(gcdr[i + 1],arr[i]);
            }
            
        
            
        
            
        
        
        
        while(q--){
            
            cin>>l>>r;
            
            
            
            if(l==1)cout<<gcdr[r+1]<<endl;
            
            else if(r==n)cout<<gcdl[l-1]<<endl;
            
            else cout<<__gcd(gcdl[l-1],gcdr[r+1])<<endl;
            
            
        }
        
    
    }
    







    return 0;
}
