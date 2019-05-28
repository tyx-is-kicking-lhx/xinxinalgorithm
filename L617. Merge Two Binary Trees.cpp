class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
    {
        if (!t1)
            return t2;
        if (!t2)
            return t1;
        TreeNode *T = new TreeNode(t1->val + t2->val);
        T->left = mergeTrees(t1->left, t2->left);
        T->right = mergeTrees(t1->right, t2->right);
        return T;
    }
};