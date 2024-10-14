// https://leetcode.com/problems/maximum-ice-cream-bars/description/?fbclid=IwZXh0bgNhZW0CMTEAAR0goVuyU2wC_5pOHBkPAZcu5aTWFbgWIF-WAtRam3SpoMK_brM8V1yPwkg_aem_rVRuQ9fmzd4e_gJ74Tr7ZA

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) 
    {
        sort(costs.begin(), costs.end());
        
        int counter=0;

        for(int i=0;i<costs.size();i++)
        {
            if(coins>=costs[i])
            {
                counter++;
                coins-=costs[i];
            }

           else
            {
                break;
            }
        }

        return counter;
    }
};
