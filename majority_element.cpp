// https://leetcode.com/problems/majority-element/

// Approach: Optimal Uses Moore's Voting ALgo:

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // using Moore's Voting ALgo, TC: O(n), SC: O(1)

        int n=nums.size();
        int ansIndex=0, count=0;

        for(int i=0; i<n; i++){
            if(nums[i]==nums[ansIndex]){
                count++;
            }
            else{
                count--;
            }
            
            // our new potential candidate:
            if(count==0){
                ansIndex=i;
                count=1;
            }
        }

        // now check for this potential candidate
        count=0;
        for(int i=0; i<n; i++){
            if(nums[i]==nums[ansIndex]) count++;
        }
        if(count>(n/2)) return nums[ansIndex];
        return -1;
    }
};
