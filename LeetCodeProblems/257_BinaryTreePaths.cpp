/*
257.Binary Tree Paths

Given the root of a binary tree, return all root-to-leaf paths in any order.
A leaf is a node with no children.
*/


std::vector<string> binaryTreePaths(TreeNode* root) 
    {
        std::vector<std::string> result{};
        std::string paths{""};

        dfs(root, paths, result);

        return result;
    }

    //Deapth first search
    void dfs(TreeNode* node, std::string path, std::vector<std::string>& result)
    {
        //if root is null
        if (node == nullptr) return;

        path += std::to_string(node->val); // path = "1" 

        //when it reaches a leaf node
        if(node->left == nullptr && node->right == nullptr)
            result.push_back(path); //adding to vector  vector_str : {"1->2->5}
     
         path += "->";

        //Do recursion    
        dfs(node->left, path, result);
        dfs(node->right, path, result);

    }
