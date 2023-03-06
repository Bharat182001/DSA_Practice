// https://leetcode.com/problems/maximum-subarray/

// KADANE's ALGO: TC: O(n), SC: O(1) -> subarray with the largest sum

    int kadane(vector<int>& nums) {
        // Kadane's Algo : TC: O(n) , SC: O(1)
        int n=nums.size();
        vector<int> temp;
        int curSum=nums[0], maxSum=nums[0];

        for(int i=1; i<n; i++){
            if(curSum>=0){
                // peeche se positive aa rha hai, train me include kr lo
                curSum += nums[i];
            }
            else{
                // peeche se -ve aa rha hai, yha se nai train shuru kr lo
                curSum = nums[i];
            }
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
