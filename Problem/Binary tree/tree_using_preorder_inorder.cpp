/*For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists.
 You just need to construct the tree and return the root.
*/

//Assume that the Binary Tree contains only unique elements. 

BinaryTreeNode<int>* buildTree(int *preorder,int startpre,int endpre,int *inorder,int startin,int endin){
    //not required
    // if(startpre==endpre){
    //     BinaryTreeNode<int>* root=new BinaryTreeNode<int>(preorder[startpre]);
    //     return root;
    // }
    if(startpre>endpre){
        return NULL;
    }
    int rootData=preorder[startpre];
    int i=startin;
    while(inorder[i]!=rootData){
        i++;
    }
    BinaryTreeNode<int>* left=buildTree(preorder,startpre+1,startpre+i-startin,inorder,startin,i-1);
    BinaryTreeNode<int>* right=buildTree(preorder,startpre+i-startin+1,endpre,inorder,i+1,endin);
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    root->left=left;
    root->right=right;
    return root;
}


BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
    int startpre=0,startin=0;
    int endpre=preLength-1;
    int endin=inLength-1;
    BinaryTreeNode<int>* ans=buildTree(preorder,startpre,endpre,inorder,startin,endin);
    return ans;
}