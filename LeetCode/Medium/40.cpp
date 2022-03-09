class Solution {
    
private:
    void solve(int i, int n, vector<int> candidates, int target, vector<int> v, vector<vector<int>>&ans)
    {
        if(target == 0){
            ans.push_back(v);
            return;
        }
        
        
        for(int j =i; j<n; j++)
        {
            
            if(j>i && candidates[j] == candidates[j-1])continue;
            
            if(candidates[j]>target)break;
            
            // vector<int>v1 = v;
            // v1.push_back(candidates[j]);
            // solve(j+1,n,candidates,target - candidates[j],v1,ans);
            
            v.push_back(candidates[j]);
            solve(j+1,n,candidates,target - candidates[j],v,ans);
            v.pop_back();
            
        }
    }
    
    
    
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>>ans;
        
        vector<int> v;
        
        sort(candidates.begin(),candidates.end());
        
        solve(0,candidates.size(),candidates,target,v,ans);
        
        return ans;
        
    }
};
