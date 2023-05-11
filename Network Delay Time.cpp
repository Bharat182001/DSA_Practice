// https://leetcode.com/problems/network-delay-time/description/

// Approach: Basic BFS!

class Solution {
public:
    int bfs(int n, int k, vector<vector<int>> &times) {
        unordered_map<int, vector<pair<int, int>> > adj;
        for(auto &it: times) {
            int u=it[0], v=it[1], tm=it[2];
            adj[u].push_back({v, tm});
        }
        queue<pair<int, int>> q;
        q.push({0, k});

        vector<int> takenTime(n+1, 1e9);
        takenTime[k]=0;

        while(!q.empty()) {
            int node=q.front().second;
            int t = q.front().first;
            q.pop();

            for(auto &ng: adj[node]) {
                int adjNode=ng.first;
                int time=ng.second;

                if(t+time<takenTime[adjNode]) {
                    //update
                    takenTime[adjNode]=t+time;
                    q.push({takenTime[adjNode], adjNode});
                }
            }
        }

        int ans=0;
        for(int i=1; i<=n; i++) {
            if(takenTime[i]==1e9) return -1;
            else {
                ans=max(ans, takenTime[i]);
            }
        }
        return ans;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        return bfs(n, k, times);
    }
};
