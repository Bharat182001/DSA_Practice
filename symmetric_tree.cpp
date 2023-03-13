// https://leetcode.com/problems/symmetric-tree/description/

// Approach: can be done using both dfs and bfs

// BFS:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void levelOrder(TreeNode* root, vector<vector<int>> &v){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int siz = q.size();
            vector<int> level;
            while(siz--){
                TreeNode* temp = q.front();
                q.pop();

                level.push_back(temp->val);

                if(temp->val == -101) continue;

                if(temp->left && temp->left->val != -101) q.push(temp->left);
                else{
                    q.push(new TreeNode(-101));
                }
                if(temp->right && temp->right->val != -101) q.push(temp->right);
                else{
                    q.push(new TreeNode(-101));
                }
            }
            v.push_back(level);
        }
    }
    bool isPalindrome(vector<int> &v){
        int i=0, j=v.size()-1;
        while(i<j){
            if(v[i] != v[j]) return false;
            i++, j--;
        }
        return true;
    }
    bool check(vector<vector<int>> &v){
        for(auto it: v){
            vector<int> temp = it;
            if(isPalindrome(temp) == false) return false;
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        // level order se:
        vector<vector<int>> v;

        levelOrder(root, v);
        return check(v);
    }
};


// DFS: 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* node1, TreeNode* node2){
        if(node1 && !node2) return false;
        else if(node2 && !node1) return false;
        else if(!node1 && !node2) return true;

        if(node1->val != node2->val) return false;

        return check(node1->left, node2->right) && check(node1->right, node2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};
