// https://leetcode.com/problems/product-of-array-except-self/description/

// Approach: Best -> TC: O(n), SC: O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // TC: O(n), SC: O(1)
        int n=nums.size();
        vector<int> ans(n, 1);

        int temp=1;
        for(int i=0; i<n; i++){
            ans[i] = ans[i] * temp;
            temp = temp * nums[i];
        }

        temp=1;
        for(int i=n-1; i>=0; i--){
            ans[i] = ans[i] * temp;
            temp = temp * nums[i];
        }

        return ans;
    }
};
