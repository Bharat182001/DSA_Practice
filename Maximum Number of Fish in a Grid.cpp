// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/

class Solution {
public:
    vector<int> dr = {1,0,-1,0};
    vector<int> dc = {0,1,0,-1};
    
    bool isValid(int x, int y, int m, int n) {
        return (x>=0 && x<m && y>=0 && y<n);
    }
    
    int solve(int x, int y, vector<vector<int>> &grid, int m, int n, vector<vector<bool>> &vis) {
        
        int temp=grid[x][y];
        vis[x][y]=true;
        
        for(int i=0; i<4; i++) {
            int nx = x + dr[i];
            int ny = y + dc[i];
            
            if(isValid(nx, ny, m, n) && grid[nx][ny]!=0 && !vis[nx][ny]) {
                vis[nx][ny]=true;
                temp += solve(nx, ny, grid, m, n, vis);
            }
        }
        
        return temp;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int ans=0;
        for(int i=0; i<m; i++) {
            int temp=0;
            for(int j=0; j<n; j++) {
                vector<vector<bool>> vis(m, vector<bool> (n, false));
                if(grid[i][j] != 0) {
                    temp = solve(i, j, grid, m, n, vis);
                    ans = max(ans, temp);
                }
            }
        }
        
        return ans;
        
    }
};
