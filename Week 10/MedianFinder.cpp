// https://leetcode.com/problems/find-median-from-data-stream/description/

class MedianFinder 
{
    priority_queue<int, vector<int>, less<>> left;
    priority_queue<int, vector<int>, greater<>> right;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) 
    {
        if( left.empty() ||num <= left.top())
        {
            left.push(num);
        }
        else
        {
            right.push(num);
        }

        if(left.size() > right.size() + 1)
        {
            right.push(left.top());
            left.pop();
        }
        else if (left.size() + 1< right.size())
        {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() 
    {
        if(left.size()==right.size())
        {
            return (left.top() + right.top())/2.0;
        }

        if(left.size()>right.size())
        {
            return left.top();
        }

        return right.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
