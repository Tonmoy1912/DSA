#include<vector>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;
    TreeNode(T data){
        this->data=data;
    }
    ~TreeNode{
        for(int i=0;i<children.size();i++){
            delete children[i];
        }
    }
};

void printTree(TreeNode<int> *root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" : ";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}

TreeNode<int>* takeInput(){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    TreeNode<int> *root=new TreeNode<int>(data);
    int numChildren;
    cout<<"Enter the number of children of "<<data<<endl;
    cin>>numChildren;
    for(int i=0;i<numChildren;i++){
        TreeNode<int> *newroot=takeInput();
        root->children.push_back(newroot);
    }
    return root;
}

TreeNode<int>* takeInput_level_wise(){
    int data;
    cout<<"Enter the root"<<endl;
    cin>>data;
    TreeNode<int> *root=new TreeNode<int>(data);
    queue<TreeNode<int>*> pendingNode;
    pendingNode.push(root);
    while(pendingNode.size()!=0){
        TreeNode<int> *front=pendingNode.front();
        pendingNode.pop();
        int numChild;
        cout<<"Enter the number of children of "<<front->data<<endl;
        cin>>numChild;
        for(int i=0;i<numChild;i++){
            int childData;
            cout<<"Enter the "<<i<<"th child of "<<front->data<<endl;
            cin>>childData;
            TreeNode<int> *child=new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNode.push(child);
        }
    }
    return root;
}

void printLevelWise(TreeNode<int>* root) {
    if(root==NULL){
        return ;
    }
    queue<TreeNode<int>*> pendingNode;
    pendingNode.push(root);
    while(!pendingNode.empty()){
        TreeNode<int> *front=pendingNode.front();
        pendingNode.pop();
        cout<<front->data<<":";
        int i=0;
        for(;i<front->children.size();i++){
            cout<<front->children[i]->data;
            pendingNode.push(front->children[i]);
            if(i<front->children.size()-1){
                cout<<",";
            }
        }
        cout<<endl;
    }
}

int num_node(TreeNode<int> *root){
    if(root==NULL){
        return 0;
    }
    if(root->children.empty()){
        return 1;
    }
    int ans=0;
    for(int i=0;i<root->children.size();i++){
        ans+=num_node(root->children[i]);
    }
    return ans+1;
}

void deleteTree(TreeNode<int> *root){
    if(root==NULL){
        return ;
    }
    for(int i=0;i<root->children.size();i++){
        deleteTree(root->children[i]);
    }
    delete root;
}