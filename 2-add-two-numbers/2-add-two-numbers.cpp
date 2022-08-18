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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* ret=dummy;
        
        int carry=0;
        while(l1 and l2)
        {  int sum=0;
            sum=(l1->val + l2->val + carry )%10;
            carry=(l1->val + l2->val + carry )/10;
         ListNode * s = new ListNode(sum);
         dummy->next=s;
         dummy=dummy->next;
         l1=l1->next;
         l2=l2->next;
        }
        while(l1)
        {
            int sum=(l1->val + carry )%10;
             carry=(l1->val + carry )/10;
            ListNode * s =new ListNode(sum);
         dummy->next=s;
         dummy=dummy->next;
            l1=l1->next;
        }
        
        while(l2)
        {
            int sum=(l2->val + carry )%10;
             carry=(l2->val + carry )/10;
            ListNode * s =new ListNode(sum);
         dummy->next=s;
         dummy=dummy->next;
            l2=l2->next;
        }
        if(carry==1)
        {
            ListNode * c=new ListNode(1);
            dummy->next=c;
            
        }
        return ret->next;
        
    }
};