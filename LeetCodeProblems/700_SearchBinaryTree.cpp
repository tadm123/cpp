/*

700. Search in a Binary Search Tree
You are given the root of a binary search tree (BST) and an integer val.
Find the node in the BST that the node's value equals val and return the subtree rooted with that node. 
If such a node does not exist, return null.
*/


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
    //using DSF
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        if (root == nullptr) return root;
    
        if (root->val == val) return root;    //if node is found return (if the current node value matches value we want to search)

        else if (root->val > val)   //if value searched is less than root node value go to left child node
            return searchBST(root->left, val);  

        else    //if (root->val < val), the value searched is greater than root node value go to right child node
            return searchBST(root->right, val);
    }
};
