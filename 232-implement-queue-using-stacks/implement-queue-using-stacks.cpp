class MyQueue {
public:
   stack<int> s;
   stack<int>l;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s.empty()){
            l.push(s.top());
            s.pop();
        }
        s.push(x);
        while(!l.empty()){
            s.push(l.top());
            l.pop();
        }
    }
    
    int pop() {
        if(s.empty()) return -1;
        int el=s.top();
        s.pop();
        return el;
    }
    
    int peek() {
        if(s.empty()) return -1;
        return s.top();
    }
    
    bool empty() {
        if(s.empty()) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */