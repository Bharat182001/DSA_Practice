// https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1


// Approach: 1: Tree Should be complete and should hold the property of max heap (root->val>child's->val)

class Solution {
  public:
    bool isCompleteTree(Node* root) {
        // while doing BFS, if we encountered a NULL node, and again found a node, that means not CBT
        // TC: O(n), SC: O(n)

        queue<Node*> q;
        q.push(root);

        bool isNullFound = false;
        while(!q.empty()){
            Node* node = q.front();
            q.pop();

            if(node == NULL) isNullFound = true;
            else{
                if(isNullFound == true) return false;

                //now we need to push nullptr also
                q.push(node->left);
                q.push(node->right); 
            }
        }

        return true;
    }
    bool isMaxHeap(Node* tree){
        if(tree==NULL) return true;
            
        if(tree->left){
            if(tree->left->data > tree->data) return false;
        }
        if(tree->right){
            if(tree->right->data > tree->data) return false;
        }
            
        return (isHeap(tree->left) && isHeap(tree->right));
    }
    
    bool isHeap(struct Node* tree) {
        return (isCompleteTree(tree) && isMaxHeap(tree));
    }
};
