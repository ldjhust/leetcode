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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (NULL == root)
        {
            return 0;
        }
        
        int LDepth = minDepth(root->left);
        int RDepth = minDepth(root->right);
        
        if (0 == LDepth)
        {
            return RDepth + 1;
        }
        
        if (0 == RDepth)
        {
            return LDepth + 1;
        }
        
        return LDepth < RDepth ? (LDepth + 1) : (RDepth + 1);
    }
};
