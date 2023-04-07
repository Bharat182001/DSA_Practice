// https://leetcode.com/problems/number-of-enclaves/

// Approach: call bfs from land boundary cells only and count lands attached to them our answer will be totallands-(lands which are attached to boundary)

class Solution {
public:
    vector<int> dr = {1,0,-1,0};
    vector<int> dc = {0,1,0,-1};

    bool isValid(int r, int c, vector<vector<int>> &grid) {
        return (r>=0 && r<grid.size() && c>=0 && c<grid[0].size());
    }
    int bfs(int row, int col, vector<vector<int>> &grid) {
        
        queue<pair<int, int>> q;
        q.push({row, col});

        grid[row][col]=0;

        int ans=1;
        while(q.size()!=0) {
            pair<int, int> p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;

            for(int i=0; i<4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(isValid(nr, nc, grid) && grid[nr][nc]==1) {
                    grid[nr][nc]=0;
                    ans++;
                    q.push({nr, nc});
                }
            }
        }

        return ans;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        // Logic: call bfs from land boundary cells only and count lands attached to them
        // our answer will be totallands-(lands which are attached to boundary)

        int m=grid.size();
        int n=grid[0].size();

        int totalLand=0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==1) totalLand++;
            }
        }

        int canWalkOff=0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i*j==0 || i==m-1 || j==n-1) { // boundary cell
                    if(grid[i][j]==1) {
                        canWalkOff += bfs(i, j, grid);
                    }
                }
            }
        }

        return totalLand-canWalkOff;
    }
};
