// https://leetcode.com/problems/count-the-number-of-complete-components/description/

class Solution {
public:
    void dfs(int node, vector<int> &temp, unordered_map<int, vector<int>> &adj, vector<bool> &vis) {
        vis[node]=true;
        temp.push_back(node);
        
        for(auto &ng: adj[node]) {
            if(!vis[ng]) {
                vis[ng]=true;
                dfs(ng, temp, adj, vis);
            }
        }
     }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int count=0;
        unordered_map<int, vector<int>> adj;
        unordered_map<int, set<int>> adjCheck;
        for(auto it: edges) {
            int u=it[0], v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            adjCheck[u].insert(v);
            adjCheck[v].insert(u);
        }
        
        
        vector<bool> vis(n, false);
        for(int i=0; i<n; i++) {
            vector<int> temp;
            if(!vis[i]) {
                dfs(i, temp, adj, vis);
                
                int a=temp.size();
                bool flag=false;
                for(int i=0; i<a; i++) {
                    for(int j=i+1; j<a; j++) {
                        if(adjCheck[temp[i]].count(temp[j]) == 0) {
                            flag=true;
                            break;
                        }
                    }
                    if(flag) break;
                }

                if(flag==false) count++;
            }
        }
        
        return count;
    }
};
