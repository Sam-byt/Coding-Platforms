// typedef pair<int,int> pi;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        vector<int>next(n,-1),prev(n,-1);
        
//         deque<pi>dq;
//         stack<pi>s;
        
        
//         ///Prev Farthest Big or Equal
//         dq.push_back({height[0],0});
//         for(int i=1;i<n;i++){
//             while(dq.front().first<height[i] && !dq.empty()){
//                 s.push(dq.front());
//                 dq.pop_front();
//             }
//             prev[i] = dq.empty()?-1:dq.front().second;
//             while(!s.empty()){
//                 dq.push_front(s.top());
//                 s.pop();
//             }
//             dq.push_back({height[i],i});
//         }
        
//         //Clearing deque
//         dq.clear();
            
// //         Next Farthest Big or Equal
//         dq.push_back({height[n-1],n-1});
//         for(int i=n-2;i>=0;i--){
//             while(dq.front().first<height[i] && !dq.empty()){
//                 s.push(dq.front());
//                 dq.pop_front();
//             }
//             next[i] = dq.empty()?-1:dq.front().second;
//             while(!s.empty()){
//                 dq.push_front(s.top());
//                 s.pop();
//             }
//             dq.push_back({height[i],i});
//         }
        
        
        for(int i=1;i<n;i++){    
            for(int j=0;j<i;j++){
                if(height[j]>=height[i]){
                    prev[i] = j;
                    break;
                }
            }
        }
        
        for(int i=n-2;i>=0;i--){    
            for(int j=n-1;j>i;j--){
                if(height[j]>=height[i]){
                    next[i] = j;
                    break;
                }
            }
        } 
            
        int ans = -1;
        int left,right;
        
        for(int i=0;i<n;i++){
            left = prev[i]==-1?0:i-prev[i];
            right = next[i]==-1?0:next[i]-i;
            
            ans = max(ans,(left+right)*height[i]);
        }
        
        return ans;
        
    }
};
