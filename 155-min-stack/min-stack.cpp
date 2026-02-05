class MinStack {
public:
    stack<long long> s;
    long long ans;
    MinStack() { ans = INT_MAX; }

    void push(int val) {
        long long x=val;
        if (s.empty()) {
            ans = x;
            s.push(x);
        } else if (ans > x) {
            s.push(2 * x - ans);
           ans=x;
        } else
            s.push(x);
    }

    void pop() {
        if (s.empty())
            return;
        if (s.top() < ans) {
            ans = 2 * ans - s.top();
        }
        s.pop();
    }

    int top() {
        if (s.empty())
            return -1;
        if (s.top() > ans) {
            return (int)s.top();
        } else
            return (int)ans;
    }

    int getMin() {
        if (s.empty())
            return -1;
        return (int)ans;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */