// https://leetcode.com/problems/min-stack/description/?envType=problem-list-v2&envId=stack

class MinStack {
    stack<int> nums;
    stack<int> minNums;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        nums.push(val);

        if(minNums.empty() || minNums.top()>=val)
        {
            minNums.push(val);
        }
    }
    
    void pop() {
        if(nums.top()==minNums.top())
        {
            minNums.pop();
        }
        nums.pop();
    }
    
    int top() {
        return nums.top();
    }
    
    int getMin() {
        return minNums.top();
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
