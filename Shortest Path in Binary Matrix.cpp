// https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

// Approach: Do it using Djikstra's Algo!

class Solution {
public:
    bool isValid(int x, int y, int n) {
        return (x>=0 && x<n && y>=0 && y<n);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //TC: O(N*N), SC:O(N)
        int n=grid.size();
        vector<vector<int>> result(n, vector<int> (n, 1e9));

        if(grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;

    pq.push({1, {0, 0}});
    result[0][0]=1;

    // right, downRight, Down, downLeft, left, topleft, top, topRight
    vector<int> dx = {0,1,1,1,0,-1,-1,-1};
    vector<int> dy = {1,1,0,-1,-1,-1,0,1};

    while(!pq.empty()) {
        auto it = pq.top();
        int node_x = it.second.first;
        int node_y = it.second.second;
        int d = it.first;
        pq.pop();

        for(int i=0; i<8; i++) {
            int nx = node_x + dx[i];
            int ny = node_y + dy[i];

            if(isValid(nx, ny, n) && grid[nx][ny]==0) {
                if(d+1 < result[nx][ny]) {
                    result[nx][ny] = d+1;
                    pq.push({d+1, {nx, ny}});
                }
            }
        }
    }
    
    if(result[n-1][n-1]==1e9) return -1;

    return result[n-1][n-1];
    }
};
