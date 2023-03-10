// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/description/

// Approach: use sliding window (2 pointer approach), TC: O(n), SC: O(1)
  
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        // sliding window approach: TC: O(n), SC: O(1)
        int n=nums.size();

        int i=0, j=0, totalSubarrays=0, currSubarrays=0;

        while(i<n && j<n){
            if(nums[j]>right){
                i = j+1;
                j++, currSubarrays=0;
            }
            else if(nums[j]>=left && nums[j]<=right){
                currSubarrays = j-i+1;
                totalSubarrays += currSubarrays;
                j++;
            }
            else if(nums[j]<left){
                // just previous calculated add kr do answer me
                totalSubarrays += currSubarrays;
                j++;
            }
        }

        return totalSubarrays;
    }
};
