https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

class Solution {
public:
    int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        // LOGIC: use djikstra's type of approach, but we need another vector [ways] to keep track of by how
        // many ways we can reach a particular node { 2 cases: 1) if we reached already with some distance and 
        // again reaching with same distance, increase ways by no. of ways of that prev node, 2) we do not increase
        // ways[adjNode] if we reach there and also updating dist[] same time }

        // creation of adjacency list
        unordered_map<int, vector<pair<int, long long int>> > adj;
        for(auto &it: roads) {
            int u=it[0];
            int v=it[1];
            int time=it[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        // TC: O(E*logV)
        // {dist, node}
        priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<>> pq; 
        pq.push({0, 0});

        vector<long long int> dist(n, 1e12), ways(n, 0);
        ways[0]=1;
        dist[0]=0;

        while(!pq.empty()) {
            auto it = pq.top();
            int node=it.second;
            long long int d=it.first;
            pq.pop();

            for(auto &ng: adj[node]) {
                int adjNode = ng.first;
                long long int newD = ng.second;

                if(d+newD < dist[adjNode]) {
                    // case 2, this is first time i am reaching with this short path
                    dist[adjNode]=d+newD;
                    ways[adjNode] = ways[node]; // naya path nhi mila, jisse aaya hu, wohi path h
                    pq.push({dist[adjNode], adjNode});
                }
                else if(d+newD == dist[adjNode]) {
                    // case 1 (updation of ways) and no need to push to pq
                    ways[adjNode] = (ways[adjNode] + ways[node])%mod;
                }
            }
        }

        return ways[n-1];
    }
};
