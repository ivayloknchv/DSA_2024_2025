// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/?fbclid=IwZXh0bgNhZW0CMTEAAR1vHQvmKGVbMH5VKjKnr54_Nhv-fZV8CIAe3aew2-rj5ykLMztxo3dSDCE_aem_ecuxYRWZ8cYwLwt821Vgnw
class Solution 
{
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) 
    {
          unordered_map<int, vector<int>> groupMap;

    for (size_t i = 0; i < groupSizes.size(); i++)
    {
        groupMap[groupSizes[i]].push_back(i);
    }

    sort(groupSizes.begin(), groupSizes.end());
    auto it = unique(groupSizes.begin(), groupSizes.end());
    groupSizes.resize(distance(groupSizes.begin(), it));
    vector<vector<int>> result;

    for (size_t i = 0; i < groupSizes.size(); i++)
    {
        const vector<int>& current = groupMap[groupSizes[i]];
        int newGroups = current.size() / groupSizes[i];
        int currentGroupIdx = result.size();
        result.resize(result.size() + newGroups);
        
        for (size_t j = 0; j < current.size(); j++)
        {
            result[currentGroupIdx].push_back(current[j]);

            if (result[currentGroupIdx].size() == groupSizes[i])
            {
                currentGroupIdx++;
            }
        }
    }
    return result;
    }
};
