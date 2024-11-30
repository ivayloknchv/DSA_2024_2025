// https://leetcode.com/problems/pascals-triangle-ii/

class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
         vector<vector<int>> pascal;

        pascal.push_back({1});

        for(int i = 1; i <= rowIndex; i++)
        {
            vector<int> currentRow(i+1);
            currentRow[0]=currentRow[i]=1;
            int iter=1;
            for(int j = 0; j < pascal[i-1].size()-1; j++)
            {
                currentRow[iter++]=pascal[i-1][j] + pascal[i-1][j+1];
            }
            pascal.push_back(currentRow);
        }

        return pascal[rowIndex];
    }
};
