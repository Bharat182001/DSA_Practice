// https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-weighted-undirected-graph
// Approach: Use same algo of djikstra's but use extra space of parent array marking/remembering that I am coming from which node

class Solution {
public:
  // TC: O(ElogV) + O(V)
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>> > adj;
        
        for(auto &it: edges) {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        vector<int> ans;
        
        vector<int> res(n+1, INT_MAX);
        vector<int> parent(n+1, 0);
        for(int i=0; i<=n; i++) {
            parent[i]=i;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        res[1]=0;
        
        while(!pq.empty()) {
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            
            for(auto &ng: adj[node]) {
                int adjNode = ng.first;
                int wt = ng.second;
                
                if(d+wt < res[adjNode]) {
                    res[adjNode] = d+wt;
                    parent[adjNode] = node;
                    pq.push({res[adjNode], adjNode});
                }
            }
        }
        
        
        int nd=n;
        if(parent[nd] == n) return {-1};
        
        while(parent[nd] != nd) {
            ans.push_back(nd);
            nd = parent[nd];
        }
        ans.push_back(1);
        
        reverse(begin(ans), end(ans));
        
        return ans;
    }
};
