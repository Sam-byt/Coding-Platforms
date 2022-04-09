typedef pair<int,int>pi;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>umap;
        for(auto i : nums){
            umap[i]++;
        }
        
        
        priority_queue<pi>pq;
        
        for(auto i:umap){
            pq.push({i.second,i.first});
        }
        
        vector<int>ans;
        
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};
