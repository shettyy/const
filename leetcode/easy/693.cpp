//https://leetcode.com/problems/binary-number-with-alternating-bits/
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int bit = n&1;
        n>>= 1;
        while(n)
        {
            if(bit == (n&1)) return false;
            else
            {
                bit = n&1;
                n>>=1;
            }
        }
        return true;
    }
};