#include<bits/stdc++.h>
int findMinimumCost(string str) {
  // Write your code here
    if(str.length() & 1)return -1;
    else{
        
        stack<char> s;
        int cntopen = 0,cntclose = 0;
        
        for(auto i : str){
            if(i == '{')s.push(i);
            else{
                if(!s.empty() && s.top() == '{')s.pop();
                else s.push(i);
            }
        }
        
        while(!s.empty())
        {
            if(s.top() == '{')cntopen++;
            else cntclose++;
            s.pop();
        }
        
        int ans = (cntopen + 1)/2 + (cntclose + 1)/2;
        
        return ans;
    }
}
