// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        // Your code here
        
        static int arr1[100001] = {0}, arr2[100001] = {0};
        
        int len1 = m - l + 1, len2 = r - m;
        
        
        
        int arrindex = l;
        
        for(int i=0; i<len1; i++)arr1[i] = arr[arrindex++];
        for(int i=0; i<len2; i++)arr2[i] = arr[arrindex++];
        
        arrindex = l;
        
        int first = 0, second = 0;
        
        while(first<len1 && second<len2)
            arr[arrindex++] = arr1[first]<arr2[second]?arr1[first++]:arr2[second++];
        
        
        while(first<len1)
            arr[arrindex++] = arr1[first++]; 
        
        while(second<len2)
            arr[arrindex++] = arr2[second++];
        
    
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l<r)
        {
            int m = l + (r -l)/2;
            
            mergeSort(arr,l,m);
            mergeSort(arr,m+1,r);
            
            merge(arr,l,m,r);
        }
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends
