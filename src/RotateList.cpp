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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((NULL == head) || (k < 0))
        {
            return NULL;
        }
        
        if (0 == k)
        {
            return head;
        }
        
        int count = 0;
        ListNode *pTmp = head;
        
        while (pTmp != NULL)
        {
            ++count;
            pTmp = pTmp->next;
        }
        
        k %= count;
        
        if (0 == k)
        {
            return head;
        }
        
        int l = count - k;
        ListNode *pS = head;
        
        while (l-- > 1)
        {
            pS = pS->next;
        }
        
        pTmp = pS;
        pS = pS->next;
        
        pTmp->next = pS->next;
        pS->next = head;
        head = pS;
        
        ListNode *pT = head;
        
        pS = pTmp->next;
        
        while (pS != NULL)
        {
            pTmp->next = pS->next;
            pS->next = pT->next;
            pT->next = pS;
            
            pT = pT->next;
            
            pS = pTmp->next;
        }
        
        return head;
    }
};