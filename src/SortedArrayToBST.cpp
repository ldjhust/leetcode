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
    TreeNode *sortedArrayToBST(vector<int> &num, int start, int end)
    {
        if (start > end)
        {
            return NULL;
        }
        
        int mid = start + ((end - start) >> 1);
        TreeNode *root = new TreeNode(0);
        
        root->val = num[mid];
        
        root->left = sortedArrayToBST(num, start, mid - 1);
        root->right = sortedArrayToBST(num, mid + 1, end);
        
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (0 == num.size())
        {
            return NULL;
        }
        
        TreeNode *root = NULL;
        int start = 0;
        int end = num.size() - 1;
        
        root = sortedArrayToBST(num, start, end);
        
        return root;
    }
};
