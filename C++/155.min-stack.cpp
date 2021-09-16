class MinStack {
    stack<int> data;
    stack<int> min;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val) {
        data.push(val);
        if(min.empty() || min.top() >= val) {
            min.push(val);
        }
    }
    
    void pop() {
        if(data.top() == min.top()) {
            min.pop();
        }
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min.top();
    }
};