// https://leetcode.com/problems/maximum-subarray/description/

Multiple approaches for this problem (Interview Specific):


1: Recursive: TLE (TC: O(n*n), SC: O(n)->recursive stack space)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {    
        return solve(nums, 0, false);
    }
    int solve(vector<int>& A, int i, bool mustPick) {
		// our subarray must contain atleast 1 element. If mustPick is false at end means no element is picked and this is not valid case
        if(i >= size(A)) return mustPick ? 0 : -1e5;       
        if(mustPick)
            return max(0, A[i] + solve(A, i+1, true));                  // either stop here or choose current element and recurse
        return max(solve(A, i+1, false), A[i] + solve(A, i+1, true));   // try both choosing current element or not choosing
    }
};

2: Recursion + Memoization: TC: O(n), SC: O(n*2) 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {    
        vector<vector<int>> dp(2, vector<int>(size(nums), -1));
        return solve(nums, 0, false, dp);
    }
    int solve(vector<int>& A, int i, bool mustPick, vector<vector<int>>& dp) {
        if(i >= size(A)) return mustPick ? 0 : -1e5;
        if(dp[mustPick][i] != -1) return dp[mustPick][i];
        if(mustPick)
            return dp[mustPick][i] = max(0, A[i] + solve(A, i+1, true, dp));
        return dp[mustPick][i] = max(solve(A, i+1, false, dp), A[i] + solve(A, i+1, true, dp));
    }
};

3: Tabulation DP: TC: O(n), SC: O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums);
        for(int i = 1; i < size(nums); i++) 
            dp[i] = max(nums[i], nums[i] + dp[i-1]);        
        return *max_element(begin(dp), end(dp));
    }
};

4: Kadane's Algo : TC: O(n), SC: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curMax = 0, maxTillNow = INT_MIN;
        for(auto c : nums)
            curMax = max(c, curMax + c),
            maxTillNow = max(maxTillNow, curMax);
        return maxTillNow;
    }
};

5: Divide and Conquer: TC: O(nlogn), SC: O(nlogn)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, size(nums)-1);
    }
    int maxSubArray(vector<int>& A, int L, int R){
        if(L > R) return INT_MIN;
        int mid = (L + R) / 2, leftSum = 0, rightSum = 0;
        // leftSum = max subarray sum in [L, mid-1] and starting from mid-1
        for(int i = mid-1, curSum = 0; i >= L; i--)
            curSum += A[i],
            leftSum=max(leftSum, curSum);
        // rightSum = max subarray sum in [mid+1, R] and starting from mid+1
        for(int i = mid+1, curSum = 0; i <= R; i++)
            curSum += A[i],
            rightSum = max(rightSum, curSum);        
		// return max of 3 cases 
        return max({ maxSubArray(A, L, mid-1), maxSubArray(A, mid+1, R), leftSum + A[mid] + rightSum });
    }	
};

6: Optimised Divide and conquer: TC: O(n), SC: O(n)
class Solution {
public:
    vector<int> pre, suf;
    int maxSubArray(vector<int>& nums) {
        pre = suf = nums;
        for(int i = 1; i < size(nums); i++)  pre[i] += max(0, pre[i-1]);
        for(int i = size(nums)-2; ~i; i--)   suf[i] += max(0, suf[i+1]);
        return maxSubArray(nums, 0, size(nums)-1);
    }
    int maxSubArray(vector<int>& A, int L, int R){
        if(L == R) return A[L];
        int mid = (L + R) / 2;
        return max({ maxSubArray(A, L, mid), maxSubArray(A, mid+1, R), pre[mid] + suf[mid+1] });
    }	
};
