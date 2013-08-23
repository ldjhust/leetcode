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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((NULL == head) || (NULL == head->next))
        {
            return head;
        }
        
        
        
        // ensure the new head
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        
        
        
        while (p1->val == p2->val)
        {
            while ((p2 != NULL) && (p1->val == p2->val))
            {
                p2 = p2->next;
            }
        
            head = p2;
            
            if ((NULL == head) || (NULL == head->next))
            {
                return head;
            }
            
            // ensure the new head
            p1 = head;
            p2 = head->next;
        }
        
        
        
        ListNode *pPre = NULL;
        p1 = head;
        p2 = head->next;
        
        while ((p1 != NULL) && (p2 != NULL))
        {
            if (p1->val != p2->val)
            {
                pPre = p1;
                p1 = p1->next;
                p2 = p2->next;
            }
            else
            {
                while ((p2 != NULL) && (p1->val == p2->val))
                {
                    p2 = p2->next;
                }
                
                // 去掉有重复的节点
                pPre->next = p2;
                
                p1 = pPre;
                p2 = p1->next;
            }
        }
        
        return head;
    }
};