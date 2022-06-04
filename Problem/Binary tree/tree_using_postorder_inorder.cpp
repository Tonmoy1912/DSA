/*For a given postorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists.
 You just need to construct the tree and return the root
*/

//Assume that the Binary Tree contains only unique elements. 

BinaryTreeNode<int>* build(int *postorder,int poststart,int postend,int *inorder,int instart,int inend){
    if(poststart>postend){
        return NULL;
    }
    int i=instart;
    int rootdata=postorder[postend];
    while(inorder[i]!=rootdata){
        i++;
    }
    BinaryTreeNode<int>* left=build(postorder,poststart,poststart+i-1-instart,inorder,instart,i-1);
    BinaryTreeNode<int>* right=build(postorder,poststart+i-instart,postend-1,inorder,i+1,inend);
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootdata);
    root->left=left;
    root->right=right;
    return root;
}


BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    BinaryTreeNode<int>* ans=build(postorder,0,postLength-1,inorder,0,inLength-1);
    return ans;
}