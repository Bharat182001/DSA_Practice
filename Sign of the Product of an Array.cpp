// https://leetcode.com/problems/sign-of-the-product-of-an-array/description/

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int n=nums.size();
        int cntNeg=0;
        for(int i=0; i<n; i++) {
            if(nums[i]==0) return 0;
            else if(nums[i]<0) cntNeg++;
        }

        if(cntNeg&1) return -1;
        return 1;
    }
};
