int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int>t(n,0);
    
    t[0] = 0;
    
    int onestep;
    int twostep = 1e9;
    
    for(int i = 1; i<n ; i++)
    {
        onestep = t[i - 1] + abs(heights[i] - heights[i-1]);
        if(i>1)twostep = t[i - 2] + abs(heights[i] - heights[i-2]);
        
        t[i] = min(onestep,twostep);
        
    }
    
    return t[n-1];
    
}
