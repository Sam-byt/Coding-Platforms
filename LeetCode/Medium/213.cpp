class Solution {
    
    
public:
    int rob(vector<int>& nums) {
        
        if(nums.size() == 1)return nums[0];
        
        int prev21 = 0,prev11 = 0, curr1 =0;
        
        for(int i =1;i<=nums.size()-1;i++)
        {
            curr1 = max(prev11 ,nums[i-1]+prev21);
            prev21 = prev11;
            prev11 = curr1;
        }
        
        
        int prev22 = 0,prev12 = 0, curr2 =0;
        
        for(int i =2;i<=nums.size();i++)
        {
            curr2 = max(prev12 ,nums[i-1]+prev22);
            prev22 = prev12;
            prev12 = curr2;
        }
        
        
        return max(prev11,prev12);
    }
};
