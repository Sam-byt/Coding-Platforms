void insertMinHeap(vector<int>&arr,int n){
    
    int temp = arr[n];
    int i =n;
    while(i>0 && temp<arr[(i-1)/2]){
        arr[i] = arr[(i-1)/2];
        i = (i-1)/2;
    }
    arr[i] = temp;
}
    


vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    for(int i=1; i<arr.size(); i++){
        insertMinHeap(arr,i);
    }
    
    return arr;
}
