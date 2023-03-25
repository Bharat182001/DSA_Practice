// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/

// Approach: use bfs to find no. of nodes in each component, then (IMP PART) => to calculate pairs in O(N)


// TC: O(n+e)
class Solution {
public:
    int bfs(int node, unordered_map<int, vector<int>> &adj, vector<bool> &vis) {

        queue<int> q;
        q.push(node);
        vis[node] = true;

        int count=1;
        while(!q.empty()) {
            int n = q.front();
            q.pop();

            for(auto vec: adj[n]) {
                if(!vis[vec]){
                    // cout<<vec<<endl;
                    vis[vec] = true;
                    q.push(vec);
                    count++;
                }
            }
        }

        return count;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        // count total nodes in each different components and push it into vector, then
        // do certain operation to get pair ka answer

        //adjacency creation
        unordered_map<int, vector<int>> adj;
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis((int)1e6+1, false);

        // bfs se each components ke nodes count kro, then
        // finding total no. of pairs:
        long long numberOfPairs = 0;
        long long sizeOfComponent = 0;
        long long remainingNodes = n;
        
        for(int node=0; node<n; node++){
            if(!vis[node]){
                sizeOfComponent = bfs(node, adj, vis);
                numberOfPairs += (sizeOfComponent)*(remainingNodes-sizeOfComponent);
                remainingNodes -= sizeOfComponent;
            }
        }

        return numberOfPairs;
    }
};
  
