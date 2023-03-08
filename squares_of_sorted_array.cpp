// https://leetcode.com/problems/squares-of-a-sorted-array/

// LOGIC: use 2 pointer approach instead of taking extra space and sorting approach

// Q: Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // TC: O(n): Logic: 2 pointers -> and extra space
        int n=nums.size();
        for(int i=0; i<n; i++) nums[i] = abs(nums[i]);

        vector<int> ans;
        int i=0, j=n-1;
        while(i!=j){
            if(nums[i]>nums[j]){
                ans.push_back(nums[i]*nums[i]);
                i++;
            }
            else{
                ans.push_back(nums[j]*nums[j]);
                j--;
            }
        }
        ans.push_back(nums[i]*nums[i]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
