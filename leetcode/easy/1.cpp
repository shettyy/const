// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> x;
        for(int j=0; j<nums.size(); j++)
        {
            int toFind = target - nums[j];
            if (m.find(toFind) != m.end()){
                x.push_back(j);
                x.push_back(m[toFind]);
                break;
            }
            m[nums[j]]=j;
        }
        return x;
    }
};