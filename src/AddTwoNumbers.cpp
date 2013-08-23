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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (NULL == l1)
        {
            return l2;
        }
        
        if (NULL == l2)
        {
            return l1;
        }
        
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        int carry = 0;
        
        while ((p1->next != NULL) && (p2->next != NULL))
        {
            p1->val += p2->val + carry;
            
            carry = p1->val / 10;
            p1->val %= 10;
            
            p1 = p1->next;
            p2 = p2->next;
        }
        
        bool bFlag = true;
        
        if ((p1->next == NULL) && (p2->next == NULL))
        {
            bFlag = false;
            
            p1->val += p2->val + carry;
            
            carry = p1->val / 10;
            p1->val %= 10;
            
            while (carry != 0)
            {
                p1->next = new ListNode(0);
                p1 = p1->next;
                
                p1->val = carry % 10;
                carry /= 10;
                
                p1->next = NULL;
            }
        }
        
        if ((p1->next != NULL) && bFlag)
        {
            p1->val += p2->val + carry;
            
            carry = p1->val / 10;
            p1->val %= 10;           
            
            while (p1->next != NULL)
            {
                p1 = p1->next;
                
                p1->val += carry;
                
                carry = p1->val / 10;
                p1->val %= 10;                
            }
            
            while (carry != 0)
            {
                p1->next = new ListNode(0);
                p1 = p1->next;
                
                p1->val = carry % 10;
                carry /= 10;
                
                p1->next = NULL;
            }
        }
        
        if ((p2->next != NULL) && bFlag)
        {
            p1->val += p2->val + carry;
            
            carry = p1->val / 10;
            p1->val %= 10;
            
            p2 = p2->next;
            
            while (p2 != NULL)
            {
                p1->next = new ListNode(0);
                p1 = p1->next;
                
                p1->val = p2->val + carry;
                
                carry = p1->val / 10;
                p1->val %= 10;
                
                p2 = p2->next;
                p1->next = NULL;
            }
            
            while (carry != 0)
            {
                p1->next = new ListNode(0);
                p1 = p1->next;
                
                p1->val = carry % 10;
                carry /= 10;
                
                p1->next = NULL;
            }
        }

        return l1;
    }
};
