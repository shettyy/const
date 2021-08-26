//https://leetcode.com/problems/reshape-the-matrix/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<int> x;
        vector<vector<int>> y;
        if(mat.size() && mat.size()*mat[0].size()==r*c)
        {
            
        }
        else return mat;
        for(auto i1:mat){
            for(auto i2:i1){
                x.push_back(i2);
            }
        }
        int count = 0;
        for(int j1=0; j1<r; j1++){
            vector<int> z;
            for(int j2=0; j2<c; j2++){
                z.push_back(x[count]);
                count++;
            }
            y.push_back(z);
        }
        return y;
    }
};