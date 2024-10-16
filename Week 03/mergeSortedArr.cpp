// https://leetcode.com/problems/merge-sorted-array/description/?envType=problem-list-v2&envId=sorting&fbclid=IwZXh0bgNhZW0CMTEAAR1KaGP2c_H477pjZzNyGUdy0IOGDwYqazktmsqMitbxii1cyVp47RcilCU_aem_NPeyoPl_u3TLnVKrHmS4vA

class Solution {
public:
   void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    vector<int> res(m + n);

    int p1 = 0, p2 = 0, idx = 0;

    while (p1 < m && p2 < n)
    {
        if (nums1[p1] < nums2[p2])
        {
            res[idx++] = (nums1[p1++]);
        }
        else
        {
            res[idx++] = (nums2[p2++]);
        }
    }

    for (int i = p1; i < m; i++)
    {
        res[idx++] = (nums1[i]);
    }

    for (int i = p2; i < n; i++)
    {
        res[idx++] = (nums2[i]);
    }

    for (int i = 0; i < m + n; i++)
    {
        nums1[i] = res[i];
    }
}
};
