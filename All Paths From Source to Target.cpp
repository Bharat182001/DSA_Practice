// https://leetcode.com/problems/all-paths-from-source-to-target/description/

// Approach: DFS+BackTracking
// K = number of paths = 2^(N-2)
// Time comlexity = E + k*V = E + 2^(N-2)*V

class Solution {
public:
    void dfs(int node, int end, unordered_map<int, vector<int>> &adj, vector<int> &ds, vector<vector<int>> &ans) {
        if(node==end) {
            ans.push_back(ds);
            return;
        }


        for(auto &ng: adj[node]) {
            ds.push_back(ng);
            dfs(ng, end, adj, ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();

        unordered_map<int, vector<int>> adj;
        for(int i=0; i<n; i++) {
            vector<int> to = graph[i];
            for(int j=0; j<to.size(); j++) {
                adj[i].push_back(to[j]);
            }
        }

        vector<vector<int>> ans;
        vector<int> ds;
        ds.push_back(0);
        
        dfs(0, n-1, adj, ds, ans);

        return ans;
    }
};
