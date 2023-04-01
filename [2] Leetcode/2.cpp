/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* res = new ListNode();
        ListNode* res_head = res;
        int dec = 0;
        
        while(l1 || l2)
        {
            int num1 = (l1) ? l1->val : 0;
            int num2 = (l2) ? l2->val : 0;
            
            int total = num1 + num2 + res->val;
            
            if(total >= 10)
            {
                ++dec;
                total -= 10;
            }
            
            res->val = total;
            
            if((l1 && l1->next) || (l2 && l2->next) || dec)
            {
                res->next = new ListNode(dec);
                res = res->next;
            }
                
            if(l1)l1 = l1->next;
            if(l2)l2 = l2->next;
            dec = 0;
        }
        return res_head;
    }
};
