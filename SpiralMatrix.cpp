// https://leetcode.com/problems/spiral-matrix/description/

// Approach : Use 4 variables for keeping track of starting row, col and ending row, col, this eleminates the need for extra boolean matrix

// TC: O(n*m), Extra SC: O(n*m)for storing the result

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        vector<int> ans;

        int sr=0, er=n-1, sc=0, ec=m-1;

        while(ans.size() < n*m) {
            for(int j=sc; j<=ec && ans.size() < n*m; j++) {
                ans.push_back(matrix[sr][j]);
            }
            sr++;
            for(int i=sr; i<=er && ans.size() < n*m; i++) {
                ans.push_back(matrix[i][ec]);
            }
            ec--;
            for(int j=ec; j>=sc && ans.size() < n*m; j--) {
                ans.push_back(matrix[er][j]);
            }
            er--;
            for(int i=er; i>=sr && ans.size() < n*m; i--) {
                ans.push_back(matrix[i][sc]);
            }
            sc++;
        }

        return ans;
    }
};
  
