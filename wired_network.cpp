// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

//Approach: Nice variant of no. of islands (I have seen editorial to get the approach, firstly i was getting wrong on approach)

// see the case if we have graph like this:

// 1---2
// |	 |
// 3---4

// 5---6
// |   |
// 7---8

// 0

// 9
// ans : totalComponenets-1 => 4-1 => 3.

class Solution {
public:
    void dfs(int node, vector<bool> &vis, unordered_map<int, vector<int>> &adj){
        vis[node] = true;
        for(auto vec: adj[node]){
            if(!vis[vec]){
                vis[vec] = true;
                dfs(vec, vis, adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        // we need atleast (n-1) cables to make all computers connected
        if(connections.size() < (n-1)) return -1;

        // Whole logic is to find the total Components in graph
        // adjacency list creation:
        unordered_map<int, vector<int>> adj;
        for(auto it: connections){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);

        int totalComponents=0;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                totalComponents++;
                dfs(i, vis, adj);
            }
        }

        return totalComponents-1;
    }
};
