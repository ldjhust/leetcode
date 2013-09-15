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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        
        if (NULL == root)
        {
            return res;
        }
        
        stack<TreeNode *> s;
        TreeNode *curr = root;
        
        while ((curr != NULL) || (!s.empty()))
        {
            while (curr != NULL)
            {
                s.push(curr);
                
                curr = curr->left;
            }
            
            curr = s.top();
            s.pop();
            
            if (curr != NULL)
            {
                res.push_back(curr->val);
            }
            
            curr = curr->right;
        }
        
        return res;
    }
};
