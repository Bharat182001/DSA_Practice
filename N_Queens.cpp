// https://leetcode.com/problems/n-queens/description/

// Approach: To find Safe Places, we can use 2 approaches :
// ->(to use loop to go to cells and check)
  
class Solution {
public:
    vector<vector<string>> ans;

    bool isSafeToPlace(int r, int c, vector<string> &ds) {

        // vertically up
        int row=r-1, col=c;
        while(row>=0) {
            if(ds[row][col]=='Q') return false;
            row--;
        }

        //horizontally left
        row=r, col=c-1;
        while(col>=0) {
            if(ds[row][col]=='Q') return false;
            col--;
        }

        //diagonally leftup
        row=r-1, col=c-1;
        while(row>=0 && col>=0) {
            if(ds[row][col]=='Q') return false;
            row--, col--;
        }

        //diagonally rightup
        row=r-1, col=c+1;
        while(row>=0 && col<ds.size()){
            if(ds[row][col] == 'Q') return false;
            row--, col++;
        }
        
        return true;
    }
    
    void solve(int r, int c, vector<string> &ds, int tq, int qpsf) {
        int n=ds.size();
        if(qpsf == tq) {
            ans.push_back(ds);
            return; 
        }

        if(c==n){
            r++, c=0;
        }
        if(r==n) {
            return;
        }

        if(isSafeToPlace(r, c, ds)){
            ds[r][c]='Q';
            solve(r+1, 0, ds, tq, qpsf+1);
            ds[r][c]='.';
        }

        solve(r, c+1, ds, tq, qpsf);
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> ds(n);
        string temp = "";
        for(int i=0; i<n; i++) temp += '.';
        for(int i=0; i<n; i++) {
            ds[i] = temp;
        }

        solve(0, 0, ds, n, 0);

        return ans;
    }
};

// ->(to use boolean vectors to mark already visited queen cells and check)
class Solution {
public:
    vector<vector<string>> ans;

    vector<bool> rightUpDiag;
    vector<bool> leftUpDiag;
    vector<bool> colMark;
    bool isSafeToPlace(int r, int c, vector<string> &ds) {

        // checking diagonal rightUp
        if(rightUpDiag[r+c]==true) return false;
        
        // checking diagonal leftUp
        if(leftUpDiag[r-c+ds.size()-1]==true) return false;

        //checking col
        if(colMark[c]==true) return false;

        return true;
    }

    void solve(int r, int c, vector<string> &ds, int tq, int qpsf) {
        int n=ds.size();
        if(qpsf == tq) {
            ans.push_back(ds);
            return; 
        }

        if(c==n){
            r++, c=0;
        }
        if(r==n) {
            return;
        }

        if(isSafeToPlace(r, c, ds)){
            ds[r][c]='Q';
            rightUpDiag[r+c]=true;
            leftUpDiag[r-c+ds.size()-1]=true;
            colMark[c]=true;

            solve(r+1, 0, ds, tq, qpsf+1);
            
            rightUpDiag[r+c]=false;
            leftUpDiag[r-c+ds.size()-1]=false;
            colMark[c]=false;
            ds[r][c]='.';
        }

        solve(r, c+1, ds, tq, qpsf);
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> ds(n);
        string temp = "";
        for(int i=0; i<n; i++) temp += '.';
        for(int i=0; i<n; i++) {
            ds[i] = temp;
        }

        rightUpDiag.resize(2*n - 1, false);
        leftUpDiag.resize(2*n - 1, false);
        colMark.resize(n, false);

        solve(0, 0, ds, n, 0);

        return ans;
    }
};
