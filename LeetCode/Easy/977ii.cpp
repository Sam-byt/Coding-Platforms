class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)nums[i]*=nums[i];
        int i;
        for(i=1;i<n;i++){
            if(nums[i]>nums[i-1])break;
        }
        int j =i;
        i--;
        
        vector<int>ans(n);
        int k =0;
        
        while(i>=0 && j<n){
            ans[k++] = nums[i]<=nums[j]? nums[i--] : nums[j++]; 
        }
        
        while(i>=0)ans[k++] = nums[i--];
        while(j<n)ans[k++] = nums[j++];
        
        return ans;
    }
};
