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
    void Reverse(ListNode *head, ListNode *tail)
    {
        if ((NULL == head) || (NULL == head->next))
        {
            return;
        }
        
        ListNode *pre = head;
        ListNode *curr = head->next;
        ListNode *next = NULL;
        
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        
        head->next = NULL;
    }

    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((NULL == head) || (NULL == head->next))
        {
            return head;
        }
        
        if (m >= n)
        {
            return head;
        }
        
        ListNode *p1 = NULL;
        ListNode *p2 = head;
        ListNode *p3 = head;
        ListNode *p4 = NULL;
        
        int i = 1;
        
        while (((i < m) || (i < n)) && (p3 != NULL))
        {
            if (i < m)
            {
                p1 = p2;
                p2 = p2->next;
                p3 = p3->next;
            }
            else
            {
                p3 = p3->next;
            }
            
            ++i;
        }
        
        if (NULL == p3)
        {
            return head;
        }
        
        p4 = p3->next;
        p3->next = NULL;
        
        Reverse(p2, p3);
        
        if (NULL == p1)
        {
            head = p3;
        }
        else
        {
            p1->next = p3;
        }
        
        p2->next = p4;
        
        return head;
    }
};