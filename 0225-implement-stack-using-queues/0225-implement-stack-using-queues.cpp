class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        int n = q.size();
        q.push(x);
        for(int i = 0;i<n;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if(empty()){
            return -1;
        }
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        if(empty()){
            return -1;
        }
        int x = q.front();
        return x;
    }
    
    bool empty() {
        if(q.empty()){
            return 1;
        }
        return 0;
    }
    
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */