int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    int prev1 = 0, prev2 = 0, curr = 0;
    
    int onestep;
    int twostep = 1e9;
    
    for(int i = 1; i<n ; i++)
    {
        onestep = prev1 + abs(heights[i] - heights[i-1]);
        if(i>1)twostep = prev2 + abs(heights[i] - heights[i-2]);
        
        curr = min(onestep,twostep);
        
        prev2  = prev1;
        prev1  = curr;
        
    }
    
    return prev1;
    
}
