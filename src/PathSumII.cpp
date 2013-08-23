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
    void Sum(TreeNode *root, int sum, vector<vector<int>> &vec, vector<int> &path)
    {
        if (NULL == root)
        {
            return;
        }
        
        if ((NULL == root->left) && (NULL == root->right))
        {
            if (sum == root->val)
            {
                path.push_back(root->val);              
                vec.push_back(path);
                
                path.pop_back();
                
                return;
            }
            else
            {
            	return;
            }
        }
        
        path.push_back(root->val);
        
        Sum(root->left, sum - root->val, vec, path);
        Sum(root->right, sum - root->val, vec, path);
        
        path.pop_back();
    }
    
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> vec;
        
        if (NULL == root)
        {
            return vec;    
        }
        
        vector<int> path;
        
        Sum(root, sum, vec, path);
        
        return vec;
    }
};
