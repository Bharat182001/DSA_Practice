// https://leetcode.com/problems/check-knight-tour-configuration/

// Just take care of edge case that knight always starts from top-left cell, i.e (0, 0)

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<pair<int, pair<int,int>>> v;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                v.push_back({grid[i][j], {i, j}});
            }
        }
        
        sort(v.begin(), v.end());
        
        // int val=v[0].first;
        int row=v[0].second.first;
        int col=v[0].second.second;
        
        if(!(row==0 && col==0)) return false;
        
        for(int i=1; i<v.size(); i++){
            int temp1 = abs(v[i].second.first-row);
            int temp2 = abs(v[i].second.second-col);
            // cout<<temp1<<" " <<temp2<<endl;
            if((temp1==2 && temp2==1) || (temp1==1 && temp2==2)){
                row = v[i].second.first;
                col = v[i].second.second;
                continue;
            }
            else return false;
        }
        
        return true;
    }
};
