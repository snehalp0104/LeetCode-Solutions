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
    bool isPalindrome(ListNode* head) {
        int count=0;
        ListNode* ans=head;
        while(ans)
        {
            count++;
            ans=ans->next;
        }
        int i=0;
        vector<int> k(count);
        while(head)
        {k[i++]=head->val;
         head=head->next;
        }
        int j,l;
        for(j=0,l=count-1;j<=l;j++,l--)
        {
            if(k[j]!=k[l])
                return false;
        }
        
        return true;
        
    }
};