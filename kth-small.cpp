// https://www.interviewbit.com/problems/kth-smallest-element-in-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void inorder(TreeNode* A, int &B, int &ans){
    if(!A)  return;
    if(B<1) return;
    inorder(A->left, B, ans);
    if(B==1)    ans = A->val;
    B--;
    inorder(A->right, B, ans);
}

int Solution::kthsmallest(TreeNode* A, int B) {
    int ans = 0;
    inorder(A, B, ans);
    return ans;
}
