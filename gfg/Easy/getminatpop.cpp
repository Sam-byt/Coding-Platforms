//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

stack<int> _push(int arr[],int n);

void _getMinAtPop(stack<int>s);

// } Driver Code Ends
//User function Template for C++

stack<int>minStack;
//Function to push all the elements into the stack.
stack<int> _push(int arr[],int n)
{
   // your code here
   while(!minStack.empty()){
       minStack.pop();
   }
   stack<int>s;
   minStack.push(arr[0]);
   s.push(arr[0]);
   
   for(int i=1;i<n;i++){
       s.push(arr[i]);
       arr[i] < minStack.top()?minStack.push(arr[i]) : minStack.push(minStack.top());    
   }
   
   return s;
}

//Function to print minimum value in stack each time while popping.
void _getMinAtPop(stack<int>s)
{
    // your code here
    while(!s.empty()){
        cout<<minStack.top()<<" ";
        minStack.pop();
        s.pop();
    }
}

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    stack<int>mys=_push(arr,n);
	    _getMinAtPop(mys);
	    
	    cout<<endl;
	    
	}
	return 0;
}


// } Driver Code Ends
