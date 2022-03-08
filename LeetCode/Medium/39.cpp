class Solution {

private:
    
    void solve(int n, vector<int> candidates,int target, vector<int>v, vector<vector<int>>&s )
    {
        if(target == 0){
            s.push_back(v);
            return;
        }
        
        if(n==0)return;
        
        if(target<candidates[n-1])
           solve(n-1,candidates,target,v,s);
        
        if(target>=candidates[n-1]){
            vector<int>v1 = v;
            v1.push_back(candidates[n-1]);
            solve(n-1,candidates,target,v,s);
            solve(n,candidates,target - candidates[n-1],v1,s);
        }
        
        
        
        
        
        
    }
    
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int>v;
        
        solve(candidates.size(),candidates,target,v,ans);
        
        
        return ans;
        
        
    }
};
