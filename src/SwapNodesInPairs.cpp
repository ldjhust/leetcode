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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (NULL == head)
        {
            return NULL;
        }
        
        if (NULL == head->next)
        {
            return head;
        }
        
        ListNode *pTmp1 = head;
        ListNode *pTmp2 = pTmp1->next;
        ListNode *pre = NULL;
        
        pTmp1->next = pTmp2->next;
        pTmp2->next = pTmp1;
        head = pTmp2;;
        
        pre = pTmp1;
        pTmp1 = pTmp1->next;
        
        if (NULL == pTmp1)
        {
            return head;
        }
        
        pTmp2 = pTmp1->next;
        
        while ((pTmp1 != NULL) && (pTmp2 != NULL))
        {
            pTmp1->next = pTmp2->next;
            pTmp2->next = pre->next;
            pre->next = pTmp2;
            
            pre = pTmp1;
            pTmp1 = pTmp1->next;
            
            if (NULL == pTmp1)
            {
                break;
            }
            
            pTmp2 = pTmp1->next;
        }
        
        return head;
    }
};
