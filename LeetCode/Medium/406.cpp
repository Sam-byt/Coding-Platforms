class Solution {
private:
    static bool compare(vector<int>v1, vector<int>v2){
        if(v1[0]>v2[0])return true;
        else if(v1[0]<v2[0])return false;
        else return v1[1]<v2[1];
    }
    
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),compare);
        
        int n = people.size();
        vector<vector<int>>ans;
        
        for(int i=0;i<n ;i++){
            int idx = people[i][1];
            ans.insert(ans.begin()+idx, people[i]);
        }
        
        return ans;
    }
};
