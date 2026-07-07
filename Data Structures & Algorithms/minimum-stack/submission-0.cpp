class MinStack {
public:
    stack<int> s;
    stack<int> min;

    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if (min.empty() || val <= min.top()) min.push(val);
    }
    
    void pop() {
        if (s.top() == min.top()) min.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min.top();
    }
};
