// https://leetcode.com/problems/rotate-array/description/

// Logic: (4 Approaches available)!
// #1. Make an extra copy and then rotate. Time complexity: O(n). Space complexity: O(n).
// #2. Start from one element and keep rotating until we have rotated n different elements. Time complexity: O(n). Space complexity: O(1).
// #3. Reverse the first n - k elements, the last k elements, and then all the n elements. Time complexity: O(n). Space complexity: O(1).
// #4. Swap the last k elements with the first k elements. The last k elements will be in the correct positions but we need to rotate 
// the remaining (n - k) elements  to the right by k steps.


// Q: Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // logic: 1. reverse first (n-k) elements, 2. reverse whole array, 3. reverse first k elements
        // TC: O(n), SC: O(1)
        int n=nums.size();
        k = k%n;

        reverse(nums.begin(), nums.begin()+(n-k));
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
    }
};
