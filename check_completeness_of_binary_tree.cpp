// https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/

// Approach: BFS -> use a boolean variable to track past, if past==false that means we haven't passes any NULL node, but if past==true, then we can't visit any node.
//   DFS:  if max_index_found > total no. of nodes -> then not a complete binary tree

BFS code: 
class Solution {
public:
    bool bfs(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);

        bool flag=false;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                TreeNode* node=q.front();
                q.pop();

                if(node->left && flag==false) q.push(node->left);
                else if(node->left && flag==true){
                    return false;
                }
                else if(!node->left){
                    flag=true;
                }
                if(node->right && flag==false) q.push(node->right);
                else if(node->right && flag==true){
                    return false;
                }
                else if(!node->right){
                    flag=true;
                }
            }
        }
        return true;
    }
    bool isCompleteTree(TreeNode* root) {
        return bfs(root);
    }
};

DFS Code: 
class Solution {
public:
    int cntNodes(TreeNode* root){
        if(root==NULL) return 0;

        return 1 + cntNodes(root->left) + cntNodes(root->right);
    }
    bool dfs(TreeNode* root, int curIdx, int totalNodes){
        // if root==NULL, that means complete binary tree hai
        if(root==NULL) return true;
        if(curIdx > totalNodes) return false;

        return dfs(root->left, 2*curIdx, totalNodes) && dfs(root->right, 2*curIdx+1, totalNodes);
    }
    bool isCompleteTree(TreeNode* root) {
        // logic -> if max_index_found > total no. of nodes -> then not a complete binary tree
        int totalNodes = cntNodes(root);

        int idx=1;
        return dfs(root, idx, totalNodes);
    }
};
