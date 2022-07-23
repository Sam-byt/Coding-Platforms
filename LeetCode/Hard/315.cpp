#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define pbds                                               \
    tree<pair<int, int>, null_type, less<pair<int, int> >, \
         rb_tree_tag, tree_order_statistics_node_update>
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>ans;
        pbds s;
        for(int i=nums.size()-1;i>=0;i--){
            if(i == nums.size()-1)ans.push_back(0);
            else ans.push_back(s.order_of_key({nums[i],i}));
            s.insert({nums[i],i});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
