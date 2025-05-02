#include <stack>

class MinStack {
private:
    std::stack<int> mainStack;  // Stores all elements
    std::stack<int> minStack;   // Tracks minimum elements

public:
    MinStack() {
        // Initialize empty stacks
    }
    
    void push(int val) {
        mainStack.push(val);
        // Push the smaller of val and current min (or val if minStack is empty)
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        if (!mainStack.empty()) {
            // If the top element is the current minimum, pop from minStack too
            if (mainStack.top() == minStack.top()) {
                minStack.pop();
            }
            mainStack.pop();
        }
    }
    
    int top() {
        return mainStack.top();  // Return top element of main stack
    }
    
    int getMin() {
        return minStack.top();   // Return top element of min stack (current min)
    }
};