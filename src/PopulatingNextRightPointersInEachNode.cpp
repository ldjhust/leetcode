/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (NULL == root)
        {
            return;
        }
        
        queue<TreeLinkNode *> q1;
        queue<TreeLinkNode *> q2;
        TreeLinkNode *tmp = NULL;
        
        q1.push(root);
        
        while (!q1.empty())
        {
            while (!q1.empty())
            {
                tmp = q1.front();
                
                q1.pop();
                
                if (q1.empty())
                {
                    tmp->next = NULL;
                }
                else
                {
                    tmp->next = q1.front();
                }
                
                if (tmp->left != NULL)
                {
                    q2.push(tmp->left);
                }
                
                if (tmp->right != NULL)
                {
                    q2.push(tmp->right);
                }
            }
            
            swap(q1, q2);
        }
    }
};