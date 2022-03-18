// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    queue<char>q;
		    string s = "";
		    int arr[26] = {0};
		    
		    
		    for(int i =0; i<A.length(); i++){
		        
		        arr[A[i]-97]++;
		        
		        q.push(A[i]);
		        
		        
		        
		        
		        while(!q.empty()){
		             if(arr[q.front() - 97]>1)q.pop();
		             else{
		                 s.push_back(q.front());
		                 break;
		             }
		        }
		        
		        if(q.empty())s.push_back('#');
		        
		        
		        
		        
		        
		        
		        
		        
		        
		    }
		    
		    return s;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
