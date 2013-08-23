/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        // two road mearge
        if (0 == lists.size())
        {
            return NULL;
        }
        
        ListNode *head = NULL;
        ListNode *tail = NULL;
        ListNode *pTmp1 = NULL;
        ListNode *pTmp2 = NULL;
        
        head = lists[0];
        
        for (vector<ListNode *>::size_type i = 1; i < lists.size(); ++i)
        {
            if (NULL == lists[i])
            {
                continue;
            }
            
            if (NULL == head)
            {
                head = lists[i];
                continue;
            }
            
            pTmp1 = head;
            pTmp2 = lists[i];
            
            if (pTmp1->val <= pTmp2->val)
            {
                head = pTmp1;
                tail = head;
                pTmp1 = pTmp1->next;
            }
            else
            {
                head = pTmp2;
                tail = head;
                pTmp2 = pTmp2->next;
            }
            
            while ((pTmp1 != NULL) && (pTmp2 != NULL))
            {
                if (pTmp1->val <= pTmp2->val)
                {
                    tail->next = pTmp1;
                    tail = tail->next;
                    pTmp1 = pTmp1->next;
                }
                else
                {
                    tail->next = pTmp2;
                    tail = tail->next;
                    pTmp2 = pTmp2->next;
                }
            }
            
            if (NULL == pTmp1)
            {
                tail->next = pTmp2;
            }
            else
            {
                tail->next = pTmp1;
            }
        } // end for
        
        return head;
    }
};
