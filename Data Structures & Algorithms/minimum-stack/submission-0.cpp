class MinStack {
public:
    vector<int> stack;
    int minVal;
    MinStack() {
        minVal = INT_MAX;
    }
    
    void push(int val) {
        stack.push_back(val);
        if (val < minVal) {
            minVal = val;
        }
    }
    
    void pop() {
        if (top() == minVal) {
            minVal = INT_MAX;
            for (int i = 0; i < stack.size()-1 ; i++) {
                if (stack[i] < minVal) {
                    minVal = stack[i];
                }
            }
        }
        stack.pop_back();
        
    }
    
    int top() {
        return stack[stack.size() - 1];
    }
    
    int getMin() {
        return minVal;
    }
};
