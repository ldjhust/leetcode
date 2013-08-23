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
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (NULL == root)
        {
            return 0;
        }
        
        int num = 0;
        int sum = 0;
        TreeNode *curr = root;
        TreeNode *previewed = NULL;
        stack<TreeNode *> s;
        
        while ((curr != NULL) || (!s.empty()))
        {
            while (curr != NULL)
            {
                s.push(curr);
                
                num *= 10;
                num += curr->val;
                
                curr = curr->left;
            }
            
            curr = s.top();
            
            if ((NULL == curr->right) || (previewed == curr->right))
            {
                if ((NULL == curr->right) && (NULL == curr->left))
                {
                    sum += num;
                }
                
                previewed = curr;
                curr = NULL;
                s.pop();
                num /= 10;
            }
            else
            {
                curr = curr->right;
            }
        } // end while
        
        return sum;
    }
};
