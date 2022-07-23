//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    private:
    int partition(int arr[], int s, int e){
        int element = arr[e];
        int pIndex = s;
        
        for(int i=s;i<e;i++){
            if(arr[i]<=element){
                swap(arr[i],arr[pIndex]);
                pIndex++;
            }
        }
        
        swap(arr[e],arr[pIndex]);
        
        return pIndex;
    }
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        if(k>0 && k<=r-l+1){
            
            int pivot = partition(arr,l,r);
            
            if(pivot - l == k - 1)return arr[pivot];
        
            else if(pivot - l > k -1)return kthSmallest(arr,l,pivot-1,k);
            
            else return kthSmallest(arr,pivot+1,r,k-pivot+l-1);
        }
        return -1;
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
