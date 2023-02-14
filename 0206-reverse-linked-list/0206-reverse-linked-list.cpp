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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL or head->next==NULL) return head;
        
        ListNode* prev=NULL;
        while(head!=NULL)
        {  ListNode* temp1=head;
           ListNode* temp=head->next;
            head->next=prev;
            prev=temp1;
            head=temp;
        }
        return prev;
    }
};