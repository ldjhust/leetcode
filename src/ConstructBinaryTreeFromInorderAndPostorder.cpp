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
    
    TreeNode *RestoreBinaryTreeFromInAndPostorder(const vector<int> &in, const int inStart, const vector<int> &post, const int postStart, const int numSize)
    {
        if (in.size() != post.size())
        {
            bFlag = false;
            
            return NULL;
        }
        
        if (0 == numSize)
        {
            return NULL;
        }
        
        int i = inStart;
        
        while ((in[i] != post[postStart]) && (i - inStart < numSize))
        {
            ++i;
        }
        
        if (i - inStart >= numSize)
        {
            bFlag = false;
            
            return NULL;
        }
        
        TreeNode *root = new TreeNode(post[postStart]);
        
        root->left = RestoreBinaryTreeFromInAndPostorder(in, inStart, post, postStart - (numSize - (i - inStart)), i - inStart);
        root->right = RestoreBinaryTreeFromInAndPostorder(in, i + 1, post, postStart - 1, numSize - (i - inStart) - 1);
        
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (inorder.size() != postorder.size())
        {
            return NULL;
        }
        
        TreeNode *root = NULL;
        
        root = RestoreBinaryTreeFromInAndPostorder(inorder, 0, postorder, postorder.size() - 1, postorder.size());
        
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