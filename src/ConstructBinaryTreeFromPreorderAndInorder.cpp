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
    bool bFlag = true;
    
    TreeNode *ReconstructTree(const vector<int> &pre, const int preStart, const vector<int> &in, const int inStart, const int Num)
    {
        if (pre.size() != in.size())
        {
            bFlag = false;
            return NULL;
        }
        
        if (0 == Num)
        {
            return NULL;
        }
        
        int i = inStart;
        
        while ((pre[preStart] != in[i]) && (i - inStart) < Num)
        {
            ++i;
        }
        
        if (i - inStart >= Num)
        {
            bFlag = false;
            
            return NULL;
        }
        
        TreeNode *root = new TreeNode(0);
        
        root->val = pre[preStart];
        
        root->left = ReconstructTree(pre, preStart + 1, in, inStart, i - inStart);
        
        root->right = ReconstructTree(pre, preStart + i - inStart + 1, in, i + 1, Num - (i - inStart + 1));
        
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode *root = NULL;
        
        if (preorder.size() != inorder.size())
        {
            return NULL;
        }
        
        root = ReconstructTree(preorder, 0, inorder, 0, inorder.size());
        
        if (bFlag)
        {
            return root;
        }
        else
        {
            return NULL;
        }
    }
};