// https://leetcode.com/problems/design-graph-with-shortest-path-calculator/description/

// Approach: Use set to keep track of size which needs to be increased (by 1 or 2), and use djikstra's algo to find shortest path!

class Graph {
public:
    int siz;
    vector<pair<int, int>> adj[102];
    unordered_set<int> nodes;

    void sp(vector<pair<int, int>> adj[], vector<int> &res, int src) {
        priority_queue<pair<int,int>> pq;
        pq.push({0, src});
        res[src]=0;

        while(!pq.empty()) {
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();

            for(auto &ng: adj[node]) {
                int adjNode=ng.first;
                int wt=ng.second;

                if(d+wt < res[adjNode]) {
                    res[adjNode] = d+wt;
                    pq.push({d+wt, adjNode});
                }
            }
        }
    }
    
    
    Graph(int n, vector<vector<int>>& edges) {
        siz=n;
        for(auto it: edges) {
            int u=it[0];
            int v=it[1];
            int cost=it[2];
            adj[u].push_back({v, cost});
            nodes.insert(u);
            nodes.insert(v);
        }
    }
    
    void addEdge(vector<int> edge) {
        int u=edge[0];
        int v=edge[1];
        int cost=edge[2];
        if(nodes.count(u)==0 && nodes.count(v)==0) siz+=2;
        else siz++;
        adj[u].push_back({v, cost});
        nodes.insert(u);
        nodes.insert(v);
    }
    
    int shortestPath(int node1, int node2) {
        
        vector<int> res(siz, INT_MAX);
        
        sp(adj, res, node1);
        
        return (res[node2]==INT_MAX) ? -1 : res[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
