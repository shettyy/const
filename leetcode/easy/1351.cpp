// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/submissions/
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        
        for(auto i:grid){
            int len=i.size();
            int index=0;
            for(int j:i){
                if(j<0){
                    cout<<index<< " ";
                    count += len-index;
                    break;
                }
            index++;
            }
        }
        return count;
    }
};