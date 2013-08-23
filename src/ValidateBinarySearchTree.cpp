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
    void inorderTravesal(TreeNode *root, vector<int> &res)
    {
        if (NULL == root)
        {
            return;
        }
        
        inorderTravesal(root->left, res);
        
        res.push_back(root->val);
        
        inorderTravesal(root->right, res);
    }

    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (NULL == root)
        {
            return true;
        }
        
        if ((NULL == root->left) && (NULL == root->right))
        {
            return true;
        }
        
        vector<int> res;
        
        inorderTravesal(root, res);
        
        for (int i = 1; i < res.size(); ++i)
        {
            if (res[i] <= res[i-1])
            {
                return false;
            }
        }
        
        return true;
    }
};