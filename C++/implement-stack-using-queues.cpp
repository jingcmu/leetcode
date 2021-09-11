class MyStack {
private:
    queue <int> q;
    
public:   
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int new_size=q.size()-1;
        // Re-queue
        while(new_size--){
            int ans=q.front();
            q.pop();
            q.push(ans);
        }   
    }
    
    int pop() {
        if(!empty()){
            int pop_ans=q.front();
            q.pop();
            return pop_ans;   
        }
        return -1;
    }
    
    int top() {
        if(!empty()){
            return q.front();
        }
        return -1;
    }
    
    bool empty() {
        if(q.empty()){
            return true;
        }
        return false;
    }
};