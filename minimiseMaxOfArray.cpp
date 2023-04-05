// https://leetcode.com/problems/minimize-maximum-of-array/description/

// Approach: we can say if maxi is max value in array, any k elements sum would be <= (k*maxi) and if
// that fails, then that maxi value would not be possible to achieve 
// binary search approach(optimal here to find which maximum value can be taken from 1 to max(nums))
// TC: O(NlogN), SC: O(1)

class Solution {
public:
    bool isValid(vector<int> &nums, int tgt) {
        int n=nums.size();
        long long int sum=0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            if(1LL*(i+1)*tgt < sum) return false;
        }

        return true;
    }
    int bs(vector<int> &nums, int lo, int hi) {

        int ans=hi;
        while(lo<=hi) {
            int mid = lo + (hi-lo)/2;
            if(isValid(nums, mid)){
                ans = mid;
                hi=mid-1; 
            }
            else{
                lo=mid+1;
            }
        }

        return ans;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        for(int i=0; i<n; i++) maxi = max(maxi, nums[i]);

        int lo=1, hi=maxi;
        return bs(nums, lo, hi); 
    }
};
