// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

// Approach: IMP => Queue would suffice for DJikstra's ALgo as we are storing on basis of steps, If we store acc to distances, then we might
// update a particular cost[node] with less cost but with wrong no. of steps and later if we found path with shorter no. of nodes(k in limit
// path), then we can't be able to choose that path, as we had already updated cost[node], so can't be able to push for that adjNode

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>> > adj;
        for(auto &it: flights) {
            int u=it[0], v=it[1], cost=it[2];
            adj[u].push_back({v, cost});
        }

        vector<int> cost(n, 1e9);
        cost[src]=0;

    // {stops, {node, dist}} => Go acc to this, not acc to distance (Must Do A Dry Run for That)!
    queue< pair<int, pair<int, int>> > q;
        q.push({0, {src, 0}});

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int dist = it.second.second;

            if(stops > (k+1)) continue;

            for(auto &ng: adj[node]) {
                int adjNode = ng.first;
                int price = ng.second;

                if(dist + price < cost[adjNode] && stops < (k+1)) {
                    //update
                    cost[adjNode] = dist+price;
                    q.push({stops+1, {adjNode, cost[adjNode]}});
                }
            }
        }

        return cost[dst]==1e9 ? -1 : cost[dst];
    }
};
