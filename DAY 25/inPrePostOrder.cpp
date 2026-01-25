/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void inorder(TreeNode* root, vector<int>& in) {
    if (!root) return;
    //LNR
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

void preorder(TreeNode* root, vector<int>& pre) {
    if (!root) return;
    //NLR
    pre.push_back(root->data);
    preorder(root->left, pre);
    preorder(root->right, pre);
}

void postorder(TreeNode* root, vector<int>& post) {
    if (!root) return;
    //LRN
    postorder(root->left, post);
    postorder(root->right, post);
    post.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root) {
    vector<int> in, pre, post;

    inorder(root, in);
    preorder(root, pre);
    postorder(root, post);

    return {in, pre, post};
}
