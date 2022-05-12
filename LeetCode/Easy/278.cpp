// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s = 1, e = n;
        int mid,ans = -1;
        while(s<=e){
            mid = s + (e-s)/2;
            isBadVersion(mid)?ans = mid,e = mid-1:s = mid+1;
        }
        
        return ans;
    }
};
