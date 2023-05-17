// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

// Approach: Use Floyd Warshall Algorithm to fill up adjacency matrix to get shortest paths from each node to every other node, then
// simply traverse adj matrix to find for each node, how many nodes are with distance(shortest) <= distanceThreshold and update ans variable

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Floyd Warshall Algo Application, TC: O(n*n*n), SC: O(n*n)
        vector<vector<int>> adj(n, vector<int> (n, 1e9));

        for(auto &it: edges) {
            int u=it[0], v=it[1], wt=it[2];
            adj[u][v]=wt;
            adj[v][u]=wt;
        }

        for(int i=0; i<n; i++) adj[i][i]=0;

        for(int via=0; via<n; via++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
                }
            }
        }

        int ans=INT_MIN, countMin=INT_MAX;
        for(int i=0; i<n; i++) {
            int count=0;
            for(int j=0; j<n; j++) {
                if(i!=j && adj[i][j] <= distanceThreshold) count++;
            }

            if(count<=countMin) {
                countMin=count;
                ans = max(ans, i);
            }
        }

        return ans;
    }
};
