#include<stack>
class SpecialStack {
    // Define the data members.
	stack<int>s;
    int low;
    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        // Implement the push() function.
        if(s.empty()){
            s.push(data);
            low = data;
        }
        else {
            if(data<low){
                s.push(2*data - low);
                low = data;
            }
            else{
                s.push(data);
            }
        }
    }

    int pop() {
        // Implement the pop() function.
        if(s.empty())return -1;
        
        int curr = s.top();
        s.pop();
        
        if(curr > low)return curr;
        else{
            int PrevMin = low;
            int val = 2*low - curr;
            low = val;
            return PrevMin;
        }
    }

    int top() {
        // Implement the top() function.
        if(s.empty())return -1;
        
        int curr = s.top();
        
        if(curr<low){
            return low;
        }
        else{
            return curr;
        }
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return s.empty();
    }

    int getMin() {
        // Implement the getMin() function.
        if(s.empty())return -1;
        
        return low;
    }  
};
