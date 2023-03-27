// https://leetcode.com/problems/minimum-path-sum/

// Approach: Dp in matrix standard problem

class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        // base case
        if(i < 0 || j < 0) return 1e9;
        if(i==0 && j == 0) return grid[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int left = grid[i][j] + solve(i, j-1, grid, dp);
        int up = grid[i][j] + solve(i-1, j, grid, dp);

        return dp[i][j] = min(left, up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        /// Rec + Memo:
        // TC: O(n*n), SC: O(n*n);
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return solve(m-1, n-1, grid, dp);
    }
};
