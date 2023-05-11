// https://leetcode.com/problems/uncrossed-lines/description/
// Approach: Use Recursive + DP Approach

// Simple recursive + MEMO: 
class Solution {
public:
    int solve(int i, int j, vector<int> &a1, vector<int> &a2, vector<vector<int>> &dp) {
        if(i>=a1.size() || j>=a2.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(a1[i]==a2[j]) {
            return dp[i][j] = 1 + solve(i+1, j+1, a1, a2, dp);
        }
        return dp[i][j] = max(solve(i+1, j, a1, a2, dp), max(solve(i, j+1, a1, a2, dp), solve(i+1, j+1, a1, a2, dp)) );
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // TC: O(n*m), SC: O(n*m)+recursive stack space=>max(n1, n2)=O(n1+n2) elements 
        int n=nums1.size(), m=nums2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return solve(0, 0, nums1, nums2, dp);
    }
};

// Tabulation:
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // TC: O(n*m),SC: O(n*m)
        int n=nums1.size(), m=nums2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                if(nums1[i]==nums2[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else dp[i][j] = max(dp[i+1][j], max(dp[i][j+1], dp[i+1][j+1]));
            }
        }

        return dp[0][0];
    }
};
