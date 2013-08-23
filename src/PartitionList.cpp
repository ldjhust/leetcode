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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (NULL == head)
        {
            return NULL;
        }
        
        ListNode *p1 = head;
        ListNode *p2 = NULL;
        
        // node insert after p3
        ListNode *p3 = NULL;
        
        while ((p1 != NULL) && (p1->val < x))
        {
            p2 = p1;
            p1 = p1->next;
        }
        
        if (NULL == p1)
        {
            return head;
        }
        
        if (head->val >= x)
        {
            while ((p1 != NULL) && (p1->val >= x))
            {
                p2 = p1;
                p1 = p1->next;
            }
            
            if (NULL == p1)
            {
                return head;
            }

            p2->next = p1->next;
            p1->next = head;
            head = p1;
            
            p1 = p2->next;
            
            p3 = head;
        }
        else
        {
            p3 = p2;
        }
        
        while (p1 != NULL)
        {
            while ((p1 != NULL) && (p1->val >= x))
            {
                p2 = p1;
                p1 = p1->next;
            }
            
            if (NULL == p1)
            {
                return head;
            }
            
            if ((p1->val < x) && (p2->val >= x))
            {
                p2->next = p1->next;
                p1->next = p3->next;
                p3->next = p1;
                    
                p1 = p2->next;
                p3 = p3->next;
            }
            else
            {
                p2 = p1;
                p1 = p2->next;
            }
        }
        
        return head;
    }
};