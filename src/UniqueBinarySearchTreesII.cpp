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
     
    TreeNode *RestoreBST(const vector<int> pre, const int preStart, const vector<int> in, const int inStart, const int inNum)
    {
        if (0 == inNum)
        {
            return NULL;
        }
        
        int i = inStart;
        
        while ((pre[preStart] != in[i]) && ((i - inStart) < inNum))
        {
            ++i;
        }
        
        if ((i - inStart) >= inNum)
        {
            bFlag = false;
            
            return NULL;
        }
        
        TreeNode *root = new TreeNode(pre[preStart]);
        
        if (bFlag)
        {
            root->left = RestoreBST(pre, preStart + 1, in, inStart, i - inStart);
        }
        else
        {
            return NULL;
        }
        
        
        if (bFlag)
        {
            root->right = RestoreBST(pre, preStart + (i - inStart + 1), in, i + 1, inNum - ((i - inStart) + 1));
        }
        else
        {
            return NULL;
        }
        
        return root;
    }

    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode *> res;
        TreeNode *root = NULL;
        
        if (n <= 0)
        {
            res.push_back(root);
            
            return res;
        }
        
        vector<int> in;
        vector<int> pre;
        
        for (int i = 1; i <= n; ++i)
        {
            in.push_back(i);
        }
        
        pre = in;
        
        bFlag = true;
        root = RestoreBST(pre, 0, in, 0, in.size());
        
        if (bFlag)
        {
            res.push_back(root);
        }
        
        next_permutation(pre.begin(), pre.end());
        
        while (pre != in)
        {
            bFlag = true;
            root = RestoreBST(pre, 0, in, 0, in.size());
        
            if (bFlag)
            {
                res.push_back(root);
            }
            
            next_permutation(pre.begin(), pre.end());
        }
        
        return res;
    }
};