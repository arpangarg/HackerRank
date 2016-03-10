/*The tree node has data, left child and right child 
struct node
{
    int data;
    node* left;
    node* right;
};

*/
int height(node * root)
{
    if(!root)
        return 0;
    else if ((root->left == 0) && (root->right == 0))
        return 1;
    else {
        return height(root->left) > height(root->right) ? 
            1 + height(root->left) : 1 + height(root->right);
    }
}
  