// https://leetcode.com/problems/calculate-money-in-leetcode-bank/submissions/
class Solution {
public:
    int totalMoney(int n) {
        int add=0;
        int count=1;
        int res=0;
        for(int i=0;i<n;i++){
            if(count==8){
                add++;
                count=1;
            }
            res+=count++ + add;
        }
        return res;
    }
};