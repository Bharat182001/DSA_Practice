// https://leetcode.com/problems/path-with-maximum-probability/description/

// Approach: Use standard djikstra's algo with slight modification in relaxation of edges (use probability vector and initialize it accordingly).

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // DJIKSTRA'S , TC: O(E*logV)
        unordered_map<int, vector<pair<int, double>> > adj;

        for(int i=0; i<edges.size(); i++) {
            int u=edges[i][0], v=edges[i][1];
            double prob=succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        queue<pair<double, int>> q;
        q.push({1, start});

        vector<double> prob(n, 0);
        prob[start]=1;

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int node=it.second;
            double p = it.first;

            for(auto &ng: adj[node]) {
                int adjNode=ng.first;
                double pr=ng.second;

                if(p*pr > prob[adjNode]) {
                    prob[adjNode]=p*pr;
                    q.push({prob[adjNode], adjNode});
                }
            }
        }

        return (prob[end]==0) ? 0 : prob[end];
    }
};
