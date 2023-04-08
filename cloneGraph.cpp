// https://leetcode.com/problems/clone-graph/description/

// Approach: Use Any Traversal DFS/BFS and use map to store [originalNode->clonedNode] to keep track whether we need to make new node or to 
// just connnect (attach the neighbors) the previous made node.

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;

        // Using BFS Traversal:
        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        q.push(node);
        Node* start = new Node(node->val);
        mp[node] = start;

        while(!q.empty()) {
            Node* n = q.front();
            q.pop();
            Node* temp = mp[n];

            for(auto it: n->neighbors) {
                if(mp.find(it) == mp.end()) {
                    Node* newNode = new Node(it->val);
                    mp[it] = newNode;
                    temp->neighbors.push_back(newNode);
                    q.push(it);
                }
                else{
                    temp->neighbors.push_back(mp[it]);
                }
            }
        }

        return start;
    }
};
