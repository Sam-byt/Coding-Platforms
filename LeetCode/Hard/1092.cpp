class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        
        int t[1001][1001];
        
        int m = str1.length(),n = str2.length();
  
        for(int i = 0; i< m+1; i++){
            for(int j=0; j<n+1; j++){
                
                if(i == 0|| j == 0)t[i][j] = 0;
                
                else if (str1[i-1] == str2[j-1]) t[i][j] =  1+ t[i-1][j-1];
                
                else t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
        
        
        int i = m,j = n;
        
        
        string str;
        
        while(i!=0 && j!=0)
        {
            if(str1[i-1]==str2[j-1])
            {
                str+=str1[i-1];
                i--;
                j--;
            }
            else
            {
                if(t[i-1][j]<t[i][j-1])
                {
                    str+=str2[j-1];
                    j--;
                }
                else
                {
                    str+=str1[i-1];
                    i--;
                }
            }
        }
        
        while(j>0)
        {
            str+=str2[j-1];
            j--;
        }
        
        while(i>0)
        {
            str+=str1[i-1];
            i--;
        }
        
        reverse(str.begin(),str.end());
        
        return str;
        
    }
};
