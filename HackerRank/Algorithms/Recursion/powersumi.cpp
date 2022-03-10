#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'powerSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER X
 *  2. INTEGER N
 */

int binexp(int x, int n)
{
    int ans = 1;
    
    while(n>0)
    {
        if(n&1)ans = ans * 1LL * x;
        n>>=1;
        x = x*1LL*x;    
    }
    
    return ans;
}

void solve(int n,vector<int>v,int target,int &cnt)
{
    if(target == 0){
        cnt++;
        return;
    }
    
    if(n==0)return;
    
    if(target>=v[n-1])
        solve(n-1,v,target - v[n-1],cnt);
        
    solve(n-1,v,target,cnt);
    
}



int powerSum(int X, int N) {
    
    int k = ceil(pow((double)X,(double)1/(double)N));
    vector<int>v(k);
    for(int i=0;i<k;i++){
        v[i] = binexp(i+1,N);
    }
    
    
    int cnt = 0;
    solve(v.size(),v,X,cnt);
    
    return cnt;
    
    
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string X_temp;
    getline(cin, X_temp);

    int X = stoi(ltrim(rtrim(X_temp)));

    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    int result = powerSum(X, N);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
