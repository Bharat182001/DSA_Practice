// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/

// Approach: I did it using DFS Only, can be done using BFS Also, TC: O(n+e), SC:O(n+e)
// Optimised approach is using DSU's(Union-Find) : which saves the space complexity a bit

class Solution {
public:
    void dfs(int node, vector<pair<int, int>> adj[], bool vis[], int end, int &mini){
        vis[node] = true;

        for(auto it: adj[node]){
            int nd = it.first;
            int dist = it.second;

            mini = min(mini, dist);

            if(!vis[nd]){
                dfs(nd, adj, vis, end, mini);
            }
        }

    }
    int minScore(int n, vector<vector<int>>& roads) {
        //adjacency list creation
        vector<pair<int, int>> adj[(int)1e5+2];
        for(int i=0; i<roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int dis = roads[i][2];
            adj[u].push_back({v, dis});
            adj[v].push_back({u, dis});
        }

        bool visited[(int)1e5+2] = {false};

        int mini = 1e5;
        dfs(1, adj, visited, n, mini);

        return mini;
    }
};

// BFS Approach:
class Solution {
public:
    int bfs(int node, vector<pair<int, int>> adj[], bool vis[], int end){
        queue<int> q;
        q.push(node);
        vis[node] = true;
        int mini = INT_MAX;
        while(!q.empty()){
            int siz = q.size();
            while(siz--){
                int node = q.front();
                q.pop();


                for(auto it: adj[node]){
                    int nd = it.first;
                    int dist = it.second;
                    mini = min(mini, dist);
                    if(!vis[nd]){
                        vis[nd] = true;
                        q.push(nd);
                    }
                }
            }
        }

        return mini;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        //adjacency list creation
        vector<pair<int, int>> adj[(int)1e5+2];
        for(int i=0; i<roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int dis = roads[i][2];
            adj[u].push_back({v, dis});
            adj[v].push_back({u, dis});
        }

        bool visited[(int)1e5+2] = {false};
        return bfs(1, adj, visited, n);
    }
};
