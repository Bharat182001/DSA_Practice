// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

// Approach: Think on why we can't store on basis of distances(costs) and rather will be storing on basis of no. of stops in queue only(No need of taking priority_queue)

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // TC: O(E), i.e O(flights.size())
        //adj list:
        unordered_map<int, vector<pair<int,int>>> adj;
        for(auto &it: flights) {
            int u = it[0], v = it[1], cost = it[2];
            adj[u].push_back({v, cost});
        }

        vector<int> distance(n, INT_MAX);
        distance[src]=0;

        // {stops, {node, dist}} 
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops>k) continue;

            for(auto &ng: adj[node]) {
                int adjNode = ng.first;
                int edgeWt = ng.second;
                if(cost+edgeWt < distance[adjNode] && stops <= k) {
                    //update
                    distance[adjNode] = cost+edgeWt;
                    q.push({stops+1, {adjNode, distance[adjNode]}});
                }
            }
        }

        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};
