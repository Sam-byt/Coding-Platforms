class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> v;
        
        
        int n = 1<<nums.size();
        
        for(int i =0; i<n;i++){
            
            int temp = i;
            
            int k = nums.size();
            
            
            while(temp>0){
                k--;
                if(temp & 1){
                    v.push_back(nums[k]);
                }
                temp>>=1;
            }
            
            ans.push_back(v);
            v.clear();
            
            
            
        }
        
        return ans;
        
    }
};
