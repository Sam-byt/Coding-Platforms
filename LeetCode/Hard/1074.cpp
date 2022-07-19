class Solution {
private:
    int subarraySum(vector<int>arr, int k){
        unordered_map<int,int>prevSum;
        int cnt = 0, currSum = 0;
        for(auto i : arr){
            currSum += i;
            if(currSum == k)cnt++;
            if(prevSum.find(currSum - k)!=prevSum.end())cnt += prevSum[currSum - k];
            prevSum[currSum]++;
        }
        
        return cnt;
    }
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0;
        for(int i=0;i<matrix.size();i++){
            vector<int>sum(matrix[0].size(),0);
            for(int j=i;j<matrix.size();j++){
                for(int k=0;k<matrix[0].size();k++){
                    sum[k] += matrix[j][k];
                }
                ans += subarraySum(sum,target);
            }
        }
        
        return ans;
    }
};
