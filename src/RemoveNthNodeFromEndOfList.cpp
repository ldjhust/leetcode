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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((NULL == head) || (n <= 0))
        {
            return NULL;
        }
        
        ListNode *pTmp = head;
        size_t k = 0;
        
        while (pTmp != NULL)
        {
            ++k;
            pTmp = pTmp->next;
        }
        
        n %= k;
        
        ListNode *pTmp1 = head;
        pTmp = head;
        
        while (n-- > 0)
        {
            pTmp1 = pTmp1->next;
        }
        
        if (pTmp == pTmp1)
        {
            // delete the first node
            head = head->next;
            
            return head;
        }
        
        while (pTmp1->next != NULL)
        {
            pTmp1 = pTmp1->next;
            pTmp = pTmp->next;
        }
        
        // delete pTmp's next node
        pTmp->next = pTmp->next->next;
        
        return head;
    }
};
