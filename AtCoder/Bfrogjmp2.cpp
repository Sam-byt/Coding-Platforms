#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define     FastIO      ios_base::sync_with_stdio(0),cin.tie(0)





int main()
{
    
    


    FastIO;

    int n,k;

    cin>>n>>k;

    vector<int>heights(n);

    for(int i=0;i<n;i++){
        cin>>heights[i];
    }



    vector<int>t(n,0);

    t[0] = 0;

    int minjmps,jmp;

    for(int i=1; i<n; i++){

        minjmps = 1e9;
        for(int j = 1; j<=k; j++){    

            if(i - j>= 0){

                jmp = t[i - j] + abs(heights[i] - heights[i - j]);
                minjmps = min(minjmps, jmp);
            }
        }
        t[i] = minjmps;
    }

    cout<<t[n-1];







    return 0;
}
