/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int>& nums,int start,int end)
    {
        if(start>end)
            return NULL;
        int mid=start + (end-start)/2;
        TreeNode* head = new TreeNode(nums[mid]);
        head->left=solve(nums,start,mid-1);
        head->right=solve(nums,mid+1,end);
        return head;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int end=n-1;
        int mid=start+(end-start)/2;
         TreeNode* head=solve(nums,start,end);
        return head;
        
        
    }
};