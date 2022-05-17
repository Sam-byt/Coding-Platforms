class Solution {
private:
    bool check(int *arr, int *brr){
        for(int i=0;i<26;i++){
            if(arr[i]!=brr[i])return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        
        if(m>n)return false;
        
        int arr[26] = {0}, brr[26] = {0};
        
        for(auto i:s1)
            brr[i-97]++;
            
        int i;
        
        for(i=0;i<m-1;i++)arr[s2[i]-97]++;
        
        int j =0;
        while(i<n){
            arr[s2[i]-97]++;
            if(check(arr,brr))return true;
            arr[s2[j]-97]--;
            i++;
            j++;
        }
        
        return false;
    }
};
