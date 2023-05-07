// https://leetcode.com/problems/surrounded-regions/description/

class Solution {
public:
    bool isValid(int x, int y, int n, int m) {
        return (x>=0 && x<n && y>=0 && y<m);
    }
    void solve(vector<vector<char>>& board) {
        //Logic: Those cells which are connected 4-directionally with border cells can't be flipped

        int n=board.size(), m=board[0].size();
        queue<pair<int, int>> q;
        // traversing borders
        for(int i=0; i<n; i++) {
            if(board[i][0]=='O') q.push({i, 0}), board[i][0]='C';
            if(board[i][m-1]=='O') q.push({i, m-1}), board[i][m-1]='C';
        }
        for(int j=0; j<m; j++) {
            if(board[0][j]=='O') q.push({0, j}), board[0][j]='C';
            if(board[n-1][j]=='O') q.push({n-1, j}), board[n-1][j]='C';
        }

        vector<int> dr={1,0,-1,0};
        vector<int> dc={0,1,0,-1};

        while(!q.empty()) {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int i=0; i<4; i++) {
                int nr=r+dr[i], nc=c+dc[i];
                if(isValid(nr, nc, n, m) && board[nr][nc]=='O') {
                    q.push({nr, nc});
                    board[nr][nc]='C';
                }
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j]=='C') board[i][j]='O';
                else board[i][j]='X';
            }
        }
    }
};
