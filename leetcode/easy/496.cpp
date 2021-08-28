// https://leetcode.com/problems/next-greater-element-i/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int, int> m;
        int s2 = nums2.size();
        for(int i=0; i<s2; i++){
            m[nums2[i]]=i;
        }
        
        vector<int> r;
        for(int i:nums1){
            int index = m[i];
            //cout<<"INDEX"<<index<<endl;
            int x=-1;
            if(index < (s2-1))
            {
                for(int j = index+1; j < s2; j++)
                {
                    cout<<j<<" ";
                    if(nums2[j] > nums2[index])
                    {
                        x=nums2[j];
                        break;
                    }
                }
                
            }

            r.push_back(x);
        }
        return r;
    }
};