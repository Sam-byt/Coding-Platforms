// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    #define ll long long
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        
        // Your code here
        for(ll i=0; i<n; i++)pq.push(arr[i]);
        
        ll a,b;
        
        ll cost = 0;
        
        while(pq.size()!=1){
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            pq.push(a+b);
            cost += (a+b);
        }
        
        return cost; 
    }
};


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends