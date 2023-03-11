// https://www.codingninjas.com/codestudio/problems/best-meeting-point_1463982?leftPanelTab=0

// Approach: Best meeting point's x coordinate will be median of all x_coordinates of houses possible in matrix, and also same for y_coordinate

#include <bits/stdc++.h> 
int findBestMeetingPoint(vector<vector<int>> &mat)
{
     int n=mat.size(), m=mat[0].size();
     vector<int> x, y;
     for(int i=0; i<n; i++){
          for(int j=0; j<m; j++){
               if(mat[i][j] == 1){
                    x.push_back(i+1);
                    y.push_back(j+1);
               }
          }
     }

     sort(x.begin(), x.end());
     sort(y.begin(), y.end());
     int mid_x = x[x.size()/2];
     int mid_y = y[y.size()/2];

     int ans=0;
     for(auto it: x){
          ans += (abs(mid_x-it));
     }
     for(auto it: y){
          ans += (abs(mid_y-it));
     }

     return ans;
}
