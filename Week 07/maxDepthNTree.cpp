/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/?envType=problem-list-v2&envId=tree

class Solution {
public:
    int dfs(Node* root)
    {
        if(!root)
        {
            return 0;
        }

        int depth = 0;
        for(auto* child: root->children)
        {
         depth = max(depth, dfs(child));
        }

        return depth +1;
    }
    int maxDepth(Node* root) 
    {
        return dfs(root);    
    }
};
