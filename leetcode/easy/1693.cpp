//https://leetcode.com/problems/sort-array-by-increasing-frequency/
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
                
        map<int, int> g;
        vector<int> h;
        for(int i:nums)
        {
            g[i]++;
            if(g[i] == 1) h.push_back(i);
        }
        vector<pair<int, int>> x;
        for(auto j:h)
        {
            pair<int, int> x1;
            x1.first = g[j];
            x1.second = j;
            x.push_back(x1);
        }
        
        sort(x.begin(), x.end());
        /********************/
        int cur = x[0].second;
        int z1 = 0, len = 0;
        vector<pair<int, int>> x1;
        for(int k1 = 0; k1 < x.size(); k1++)
        {
            if(cur == x[k1].first)
            {
                len++;
            }
            else
            {
                for(int k2=(z1+len-1); k2>=(z1); k2--)
                {
                    x1.push_back(x[k2]);
                }
                z1 = k1;
                cur = x[k1].first;
                len = 1;
                
            }
        }
        for(int k2=(z1+len-1); k2>=(z1); k2--)
        {
            x1.push_back(x[k2]);
        }
        /*********************/
        vector<int> z;
        
        for(auto k:x1)
        {
            for(int l=0; l < k.first; l++)
            {
                z.push_back(k.second);
            }
        }
        
        
        return z;
    }
};