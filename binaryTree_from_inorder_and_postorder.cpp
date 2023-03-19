// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

// Approach: use recursion and play with indices well
// TIP: Important for Freshers Interviews

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
    TreeNode* solve(vector<int> & inorder, vector<int>& postorder, int is, int ie, int ps, int pe, int n){
        //base case:
        // if(is<0 || ie>=n || ps<0 || pe>=n) return NULL;
        if(is>ie || ps>pe) return NULL; // need to know HOW?

        TreeNode* root = new TreeNode(postorder[pe]);

        int rootIdx=-1;
        for(int i=is; i<=ie; i++){
            if(inorder[i] == root->val){
                rootIdx = i;
                break; 
            }
        }

        int leftSiz = rootIdx-is;
        int rightSiz = ie-rootIdx;
        root->left = solve(inorder, postorder, is, rootIdx-1, ps, ps+leftSiz-1, n);
        root->right = solve(inorder, postorder, rootIdx+1, ie, pe-rightSiz, pe-1, n);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int inStart = 0, inEnd = n-1;
        int postStart = 0, postEnd = n-1; 
        return solve(inorder, postorder, inStart, inEnd, postStart, postEnd, n);
    }
};
