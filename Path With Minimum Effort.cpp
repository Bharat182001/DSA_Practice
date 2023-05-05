// https://leetcode.com/problems/path-with-minimum-effort/

// Approach: Use Djikstra's algo with nice dry run of test cases!

class Solution {
public:
    bool isValid(int x, int y, int n, int m) {
        return (x>=0 && x<n && y>=0 && y<m);
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>> effort(n, vector<int> (m, 1e9));

        // Type: (effort, {row, col})
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> que;
        que.push({0, {0, 0}});
        effort[0][0]=0;

        vector<int> dx = {1,0,-1,0};
        vector<int> dy = {0,1,0,-1};

        while(!que.empty()) {
            auto it = que.top();
            que.pop();

            int x = it.second.first;
            int y = it.second.second;
            int orig_effort = it.first;

            if(x==n-1 && y==m-1) return orig_effort; // some more optimisation

            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(isValid(nx, ny, n, m)) {
                    int cur_effort = max(abs(heights[x][y] - heights[nx][ny]), orig_effort);

                    if(cur_effort < effort[nx][ny]) {
                        //update
                        effort[nx][ny] = cur_effort;
                        que.push({cur_effort, {nx, ny}});
                    }
                }
            }
        }

        return 0; // unreachable.
    }
};
