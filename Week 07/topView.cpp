/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

// https://www.hackerrank.com/contests/sda-hw-6/challenges/tree-top-view/problem

*/

     void topView(Node* root)
    {
        if (!root)
        {
            return;
        }

        unordered_map<int, int> topNodes;

        int minIdx = 0;
        int maxIdx = 0;

        queue<pair<Node*, int>> q;
        q.push({ root, 0 });


        while (!q.empty())
        {
            pair<Node*, int> curr = q.front();
            q.pop();

            if (topNodes[curr.second] == 0)
            {
                topNodes[curr.second] = curr.first->data;
            }

            if (curr.first->left)
            {
                q.push({ curr.first->left, curr.second - 1 });
                minIdx = min(minIdx, curr.second-1);
            }
            if (curr.first->right)
            {
                q.push({ curr.first->right, curr.second + 1 });
                maxIdx = max(maxIdx, curr.second+1);
            }
        }
        for (int i = minIdx; i <= maxIdx; i++)
        {
            std::cout << topNodes[i] << ' ';
        }
    }
