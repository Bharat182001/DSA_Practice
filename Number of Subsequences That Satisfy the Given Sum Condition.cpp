// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/

// Approach: sort the array first (nhi to we can't be able to reduce complexity from (2^n)*n to nlogn), then apply IMP => (binary search to find min and max elements range)!  

class Solution {
public:
    int mod = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        sort(begin(nums), end(nums));
        
        vector<long long> store2pow(n, 1);
        for(int i=1; i<n; i++) {
            store2pow[i] = (store2pow[i-1]*2)%mod;
        }

        long long ans=0;

        int left=0, right=n-1;
        while(left<=right) {
            if(nums[left]+nums[right] <= target) {
                //calculate ans:
                ans = (ans+store2pow[right-left])%mod;

                left++;
            }
            else {
                right--;
            }
        }

        return ans;
    }
};
