//https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        std::map<int, int> countMap;
        int res = 0;
        for(int i:nums)
        {
            countMap[i]++;
            if(countMap[i]>1)
            {
                return i;
            }
                
        }
        return 0;
    }
};