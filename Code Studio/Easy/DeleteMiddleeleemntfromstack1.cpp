void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
    stack<int> s;
    
    int n = N/2;
    
    while(n--)
    {
        s.push(inputStack.top());
        inputStack.pop();
    }
    
    inputStack.pop();
    
    while(!s.empty())
    {
        inputStack.push(s.top());
        s.pop();
    }
   
}
