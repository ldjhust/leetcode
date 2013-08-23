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
    void preBT(TreeNode *root, queue<TreeNode *> &q)
    {
        if (NULL == root)
        {
            return;
        }
        
        q.push(root);
        
        preBT(root->left, q);
        
        preBT(root->right, q);
    }

    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (NULL == root)
        {
            return;
        }
        
        queue<TreeNode *> q;
        
        preBT(root, q);
        
        TreeNode *pTmp = NULL;
        
        while (!q.empty())
        {
            pTmp = q.front();
            
            q.pop();
            
            if (!q.empty())
            {
                pTmp->right = q.front();
            }
            else
            {
                pTmp->right = NULL;
            }
            
            pTmp->left = NULL;
        }
    }
};