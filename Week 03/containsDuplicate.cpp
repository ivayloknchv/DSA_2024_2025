// https://leetcode.com/problems/contains-duplicate-ii/description/?fbclid=IwZXh0bgNhZW0CMTEAAR2ZFaipLkE7xn104yPN6mHnp4BR_iyz0DzMsOo8VlqXzIWo0lhY9fhbY0w_aem_7OMuYLlx5hJq-pqT59xKIw

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
{
    vector<pair<int, int>> vec;

    for (size_t i = 0; i < nums.size(); i++)
    {
        vec.push_back({ nums[i],i });
    }

    sort(vec.begin(), vec.end());


    for (size_t i = 0; i < vec.size() - 1; i++)
    {
        if (vec[i].first == vec[i + 1].first && abs(vec[i].second - vec[i + 1].second) <= k)
        {
            return true;
        }
    }

    return false;
}

};
