class Solution {
//     int t[3001][3001];
//     int solve(int i, int prev, vector<int>nums){
//         if(i==nums.size())return 0;
//         if(t[i][prev+1] != -1)return t[i][prev+1];
//         int len =0;
//         if(prev<0)
//             len = max(1+solve(i+1,i,nums),solve(i+1,prev,nums));
        
//         if(prev>=0){
//             len = nums[i]>nums[prev]?max(1+solve(i+1,i,nums),solve(i+1,prev,nums)):solve(i+1,prev,nums);    
//         }
        
//         return t[i][prev+1] = len;
    // }
public:
    int lengthOfLIS(vector<int>& nums) {
        // memset(t,-1,sizeof(t));
        // return solve(0,-1,nums);
        
        int t[3001][3001] = {0};
        int n = nums.size();
        
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--)
                t[i][j+1] = j<0?max(1+t[i+1][i+1],t[i+1][j+1]):(nums[i]>nums[j]?max(1+t[i+1][i+1],t[i+1][j+1]):t[i+1][j+1]); 
        }
        
        return t[0][-1+1];
    }
};
