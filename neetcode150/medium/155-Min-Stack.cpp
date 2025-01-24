#include <stack>

using namespace std;

/**
 * Solution
 * 
 * 1. Using stack<pair<int, int>> (val, minVal)
 * 2. stack.top().second is the current min value
 * 
 * Time  : O(1) for every method
 * Space : O(N) stack size
 */
class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        int minVal = st.empty() ? val : min(val, st.top().second);
        st.push({val, minVal});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }

private:
    stack<pair<int, int>> st;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */