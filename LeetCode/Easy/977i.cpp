class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]*=nums[i];
        }
        int j = nums.size()-1;
        while(j>0){
            if(nums[0]<=nums[j])j--;
            else{
                nums.insert(nums.begin()+j+1,nums[0]);
                nums.erase(nums.begin());
                j++;
            }
        }
        
        return nums;
        
    }
};
