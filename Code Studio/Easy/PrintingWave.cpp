vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    //Write your code here
    vector<int> ans ;
    for(int j = 0; j<mCols; j++)
    {
        if(j&1)
        {
            for(int i = 0; i<nRows; i++)ans.push_back(arr[nRows - i - 1][j]);
        }
        else
            for(int i=0; i<nRows; i++)ans.push_back(arr[i][j]);
    }
    
    return ans;
}
