// https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/description/

class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &arr, int n, int m, vector<vector<int>> &dp) {
        if(i==n || j==m || i<0 || j<0) return -1e9;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int move1=0, move2=0, move3=0;
        
        if(i-1>=0 && j+1<m && arr[i-1][j+1] > arr[i][j]) move1 = (1 + solve(i-1, j+1, arr, n, m, dp));
        
        if(i<n && j+1<m && arr[i][j+1] > arr[i][j]) move2 = 1 + solve(i, j+1, arr, n, m, dp);
        
        if(i+1<n && j+1<m && arr[i+1][j+1] > arr[i][j]) move3 = 1 + solve(i+1, j+1, arr, n, m, dp);
        
        return dp[i][j] = max(move1, max(move2, move3));
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size(); // nxm
        
        int ans=0;
        
        vector<vector<int>> dp(n+1, (vector<int> (m+1, -1)));
        for(int i=0; i<n; i++) {
            ans = max(ans, solve(i, 0, grid, n, m, dp));
            dp.resize(n+1, vector<int> (m+1, -1));
        }
        
        return ans;
    }
};
