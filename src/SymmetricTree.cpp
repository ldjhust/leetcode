/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // 递归版
class Solution {
public:

    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((NULL == p) && (NULL == q))
        {
            return true;
        }
        
        if ((NULL == p) || (NULL == q))
        {
            return false;
        }
        
        if (p->val != q->val)
        {
            return false;
        }
        
        return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
    }
    
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (NULL == root)
        {
            return true;
        }
        
        if ((NULL == root->left) && (NULL == root->right))
        {
            return true;
        }
        
        return isSameTree(root->left, root->right);
    }
};

// 迭代版
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
    void LevelOrderNLR(TreeNode *root, vector<string> &vec)
    {
        
        if (NULL == root)
        {
            return;
        }
        
        queue<TreeNode *> q;
        
        q.push(root);
        
        bool bFlag = false;
        
        while (0 != q.size())
        {
            // change int to string
            string tmp;
            ostringstream convert;
            
            TreeNode *pTmp = q.front();
            
            q.pop();
            
            convert << pTmp->val;
            tmp = convert.str();
            
            vec.push_back(tmp);
            
            if (bFlag)
            {
            	vec.push_back("#");
            	bFlag = false;
            }
                                            
            if (NULL == pTmp->left)
            {
                vec.push_back("#");
            }
            else
            {
                q.push(pTmp->left);
            }
            
            if (NULL == pTmp->right)
            {
               bFlag = true;
            }
            else
            {
                q.push(pTmp->right);
            }
        }
        
        return;
    }
    
    void LevelOrderNRL(TreeNode *root, vector<string> &vec)
    {
        
        if (NULL == root)
        {
            return;
        }
        
        queue<TreeNode *> q;
        
        q.push(root);
        
        bool bFlag = false;
        
        while (0 != q.size())
        {
            // change int to string
            string tmp;
            ostringstream convert;
            
            TreeNode *pTmp = q.front();
            
            q.pop();
            
           	convert << pTmp->val;
           	tmp = convert.str();
            
           	vec.push_back(tmp);
           	
           	if (bFlag)
           	{
           		vec.push_back("#");
           		bFlag = false;
           	}
            
            if (NULL == pTmp->right)
            {
                vec.push_back("#");
            }
            else
            {
                q.push(pTmp->right);
            }
            
            if (NULL == pTmp->left)
            {
                bFlag = true;
            }
            else
            {
                q.push(pTmp->left);
            }
        }
        
        return;
    }
    
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (NULL == root)
        {
            return true;
        }
        
        if ((NULL == root->left) && (NULL == root->right))
        {
            return true;
        }
        
        if ((NULL == root->left) || (NULL == root->right))
        {
            return false;
        }
        
        vector<string> vec1;
        vector<string> vec2;
        
        LevelOrderNLR(root->left, vec1);
        LevelOrderNRL(root->right, vec2);
        
        vector<string>::const_iterator iter1 = vec1.begin();
        vector<string>::const_iterator iter2 = vec2.begin();
        
        for (; (iter1 != vec1.end()) && (iter2 != vec2.end());)
        {
            
            if (*iter1 != *iter2)
            {
                
                return false;
            }
            else
            {
                ++iter1;
                ++iter2;
            }
        }
              
        return true;
    }
};
