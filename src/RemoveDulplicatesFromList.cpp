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
        
        ListNode *p1 = head;
        ListNode *p2 = p1->next;
        
        while (p1->next != NULL)
        {
            if (p1->val == p2->val)
            {
                p1->next = p2->next;
                delete p2;
                
                p2 = p1->next;
            }
            else
            {
                p1 = p2;
                p2 = p2->next;
            }
        }
        
        return head;
    }
};
