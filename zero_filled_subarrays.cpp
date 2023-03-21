// https://leetcode.com/problems/number-of-zero-filled-subarrays/description/

// Approach: use 2-pointers and a single scan , TC: O(n), SC: O(1)

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();

        int i=0, j=0;
        while(j<n){
            if(nums[j] == 0){
                j++;
            }
            else{
                int temp = j-i;
                ans += (1LL*temp)*(temp+1)/2;
                i=j;
                i++, j++;
            }
        }
        int temp = j-i;
        ans += (1LL*temp)*(temp+1)/2;

        return ans;
    }
};
