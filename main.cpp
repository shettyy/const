//
//  main.cpp
//  const
//
//  Created by Abhishek Shetty on 23/10/21.
//

#include <iostream>
#include <vector>
using namespace std;
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> x;
        for (auto i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            if (m.find(diff) != m.end())
            {
                x.push_back(i);
                x.push_back(m[diff]);
                break;
            }
            m[nums[i]] = i;
        }
        return x;
    }
    //https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int maxProfit = 0;
        for(int i=1; i < prices.size(); i++)
        {
            if (min > prices[i])
            {
                min = prices[i];
            }
            
            if (maxProfit < (prices[i] - min))
            {
                maxProfit = prices[i] - min;
            }
            
            
            
        }

        return maxProfit;
    }
};

int main() {
    cout << "Hello, World!!\n";
    Solution sol;
    vector v = {1,2,3};
    for(auto i: v) cout<<i<< " ";
    vector v2 = sol.twoSum(v, 3);
    return 0;
}
