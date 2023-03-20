// https://leetcode.com/problems/kth-largest-element-in-an-array/

// Approach: Use minHeap

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int, vector<int>, greater<int>> minHp;
        for(int i=0; i<n; i++){
            minHp.push(nums[i]);
            if(minHp.size() > k) minHp.pop();
        }

        return minHp.top();
    }
};
