/*
Given the root of a binary tree, invert the tree, and return its root.
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
    TreeNode* invertTree(TreeNode* root) 
    {
        if (root == nullptr) return root;        //base if children are null

        //Swapping children
        TreeNode *temp = root->left;    //starting a temporary node that will be equal to the left-hand children node, whose val will be 2

        root->left = root->right; //7   7
        root->right = temp; //7   2

        //recursively run inverTree on all children from left to right
        invertTree(root->left); //swapping all left hand child nodes
        invertTree(root->right); //swapping all right hand child nodes

        return root;
    }
};
