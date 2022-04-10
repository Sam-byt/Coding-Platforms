class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int>ans;
        for(auto i:ops){
            if(i == "C")ans.pop_back();
            else if(i == "D")ans.push_back(2*ans.back());
            else if( i == "+")ans.push_back(*(ans.end() - 1) + *(ans.end() - 2));
            else{
                if(i[0] == '-'){
                    ans.push_back((-1)*stoi(i.substr(1)));
                }
                else{
                    ans.push_back(stoi(i));
                }
            }
        }
        
        return accumulate(ans.begin(),ans.end(),0);
    }
};
