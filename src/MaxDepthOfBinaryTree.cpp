/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (NULL == root)
        {
            return 0;
        }
        
        int LDepth = maxDepth(root->left);
        int RDepth = maxDepth(root->right);
        
        return LDepth > RDepth ? (LDepth + 1) : (RDepth + 1);
    }
};
