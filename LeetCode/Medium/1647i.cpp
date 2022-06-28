class Solution {
public:
    int minDeletions(string s) {
        unordered_map<int,int>occurance;
        unordered_map<char,int>freq;
        
        for(auto i : s){
            freq[i]++;
        }
        
        for(auto i : freq){
            occurance[i.second]++;
        }
        
        
        vector<pair<int,char>>v;
        
        for(auto i : freq)v.push_back({i.second,i.first});
        
        sort(v.begin(),v.end());
        
        int cnt = 0;
        
        for(int i=v.size()-1; i>=0; i--){
            while(occurance[v[i].first]>1){
                cnt++;
                occurance[v[i].first]--;
                v[i].first--;
                if(v[i].first == 0)break;
                occurance[v[i].first]++;
            }
        }
        
        return cnt;
        
    }
};
