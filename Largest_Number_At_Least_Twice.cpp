// https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/

// Approach: TC: O(n), compute 2 largest elements and check if they meet condition or not

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        // TC: O(n), SC: O(1)
        int n=nums.size();
        int max1=INT_MIN, max2=INT_MIN;

        for(int i=0; i<n; i++){
            if(nums[i]>=max1){
                max2=max1;
                max1=nums[i];
            }
            else if(nums[i]>=max2){
                max2=nums[i];
            }
        }

        if(max1>=(max2*2)){
            for(int i=0; i<n; i++){
                if(nums[i]==max1) return i;
            }
        }

        return -1;
    }
};
  
