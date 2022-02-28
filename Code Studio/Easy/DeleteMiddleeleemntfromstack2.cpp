
void solve(stack<int>&s, int cnt, int n)
{
    if(cnt == n/2){
        s.pop();
        return;
       
    }
    
    int temp = s.top();
    s.pop();
    
    
    solve(s,cnt+1,n);
    s.push(temp);
}

void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
    int cnt = 0;
    
	solve(inputStack, cnt,N);    
   
}
