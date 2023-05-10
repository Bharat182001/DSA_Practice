// https://leetcode.com/problems/spiral-matrix-ii/description/

// Approach: Same as Spiral Matrix (LeetCode), just take a variable to fill matrix 

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int> (n, 0));

        int sRow=0, eRow=n-1, sCol=0, eCol=n-1;

        int fill=1;

        while(fill<=n*n) {
            for(int j=sCol; j<=eCol && fill<=n*n; j++) {
                ans[sRow][j]=(fill++);
            }
            sRow++;

            for(int i=sRow; i<=eRow && fill<=n*n; i++) {
                ans[i][eCol]=(fill++);
            }
            eCol--;

            for(int j=eCol; j>=sCol && fill<=n*n; j--) {
                ans[eRow][j]=(fill++);
            }
            eRow--;

            for(int i=eRow; i>=sRow && fill<=n*n; i--) {
                ans[i][sCol]=(fill++);
            }
            sCol++;
        }

        return ans;
    }
};

  
