// https://leetcode.com/problems/implement-stack-using-queues/description/?envType=problem-list-v2&envId=queue

class MyStack 
{
    queue<int> q1;
    
public:
    MyStack() 
    {}
    
    void push(int x) 
    {
        q1.push(x);    
    }
    
    int pop() 
    {
        queue<int> q2;
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int ans=q1.front();
        q1=q2;
        return ans;
    }
    
    int top() 
    {
        queue<int> q2;
         while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int ans=q1.front();
        q2.push(q1.front());
        q1=q2;
        return ans;
    }
    
    bool empty() 
    {
        return q1.empty();    
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
