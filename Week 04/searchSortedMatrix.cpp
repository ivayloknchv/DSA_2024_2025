// https://leetcode.com/problems/search-a-2d-matrix-ii/description/?envType=problem-list-v2&envId=binary-search

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int row = 0;
        int col = matrix[0].size() - 1;

        int m = matrix.size();

        while(row<m && col>=0)
        {
            if(matrix[row][col] == target)
            {
                return true;
            }
            else if(matrix[row][col]>target)
            {
                col--;
            }
            else
            {
                row++;
            }
        }

        return false;
    }
};
