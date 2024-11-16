// https://leetcode.com/problems/my-calendar-i/description/

struct Node
{
    int start = 0;  // [start; end)
    int end = 0;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int start, int end, Node* left = nullptr, Node* right = nullptr)
    : start(start), end(end), left(left), right(right)
    {}
};



class MyCalendar 
{
    Node* root = nullptr;
public:
    MyCalendar() 
    {}
    
    Node* check(int startTime, int endTime, Node* curr, bool& ans)
    {
        if(!curr)
        {
            ans=true;
            return new Node(startTime, endTime);
        }

        if(curr->end > startTime && endTime > curr->start)
        {
            ans=false;
            return curr;
        }

        if(curr->start>=endTime)
        {
            curr->left=check(startTime, endTime, curr->left, ans);
        }
        if(curr->end<=startTime)
        {
            curr->right=check(startTime, endTime, curr->right, ans);
        }
        return curr;
    }
    bool book(int startTime, int endTime) 
    {
        bool ans=false;
        root = check(startTime, endTime, root, ans);
        return ans;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
