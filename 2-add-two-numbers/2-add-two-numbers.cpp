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
       ListNode* temp1=l1; 
          ListNode* temp2=l2;
       vector<int> s1;
       vector<int> s2;
        while(temp1!=NULL)
        {
            s1.push_back(temp1->val);
            temp1=temp1->next;
        }
         while(temp2!=NULL)
        {
            s2.push_back(temp2->val);
            temp2=temp2->next;
        }
        int carry=0;
        vector<int> ans;
        int size1=s1.size();
        int size2=s2.size();
       int diff=abs(size1-size2);
        if(s1.size()<s2.size())
            while(diff--)
                s1.push_back(0);
        if(s2.size()<s1.size())
            while(diff--)
                s2.push_back(0);
        reverse(s1.begin(),s1.end());
          reverse(s2.begin(),s2.end());
        int l=s1.size();
        for(int i=l-1;i>=0;i--)
        {
            int sum=(s1[i]+s2[i]+carry)%10;
             carry=(s1[i]+s2[i]+carry)/10;
            ans.push_back(sum);
        }
        if(carry==1)
            ans.push_back(carry);
        int n=ans.size();
        ListNode *res=new ListNode(ans[0]);
        ListNode *dummy=res;
        for(int i=1;i<n;i++)
        {
            ListNode *l=new ListNode(ans[i]);
            dummy->next=l;
            dummy=dummy->next;
        }
        
     
       return res; 
    }
};