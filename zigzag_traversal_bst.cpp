// https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int> > ans;
    if(!A)  return ans;
    queue<TreeNode*> q;
    TreeNode* it = A;
    q.push(it);
    bool odd = true;
    while(!q.empty()){
        int elem = q.size();
        vector<int> v(elem, 0);
        int i = elem;
        for(int i=0; i<elem; i++)
        {
            it = q.front();
            q.pop();
            if(odd) v[i] = it->val;
            else    v[elem-1-i] = it->val;
            if(it->left)    q.push(it->left);
            if(it->right)   q.push(it->right);
        }
        ans.push_back(v);
        odd = !odd;
    }
    return ans;
}
