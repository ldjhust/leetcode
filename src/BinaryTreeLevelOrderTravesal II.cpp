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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> vec;
           
           if (NULL == root)
           {
               return vec;
           }
           
           queue<TreeNode *> tmp1;
           queue<TreeNode *> tmp2;
           vector<int> tmp;
           
           tmp1.push(root);
           
           while (!(tmp1.empty()))
           {
               while (!(tmp1.empty()))
               {
                   TreeNode *pNode = tmp1.front();
                   
                   tmp1.pop();
                   
                   tmp.push_back(pNode->val);
                   
                   if (pNode->left != NULL)
                   {
                       tmp2.push(pNode->left);
                   }
                   
                   if (pNode->right != NULL)
                   {
                       tmp2.push(pNode->right);
                   }
               }
               
               vec.push_back(tmp);
               
               tmp.clear();
               
               swap(tmp1, tmp2);
           }
           
           reverse(vec.begin(), vec.end());
           
           return vec;
    }
};