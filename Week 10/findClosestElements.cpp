// https://leetcode.com/problems/find-k-closest-elements/description/?envType=problem-list-v2&envId=heap-priority-queue

struct MyCmp
{
  int x;
  MyCmp(int x):x(x)
  {}

  bool operator()(int a, int b)
  {
    if(abs(a-x)==abs(b-x))
    {
      return a<b;
    }

    return abs(a-x) < abs(b-x);
  }
};

class Solution 
{

public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        MyCmp cmp(x);
        priority_queue<int, vector<int>, MyCmp> pq(cmp);

        for(int i = 0; i < k; i++)
        {
            pq.push(arr[i]);
        }

        for(int i = k; i < arr.size(); i++)
        {
            if(cmp(arr[i], pq.top()))
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }

        vector<int> ans;

        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
