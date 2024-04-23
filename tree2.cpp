
#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node*right;
    Node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;

    }
    

};
Node * createNode(){
    cout<<"Enter the value";
    int value;
    cin>>value;
    if(value==-1){
        return NULL;
    }
    Node* root= new Node(value);
    root->left=createNode();
    root->right=createNode();
    return root;
}
// Tree Traversal methods
void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    //N L R
    cout<<root->data<<"";
    //L
    preOrder(root->left);
    //R
    preOrder(root->right);

    

}
void inOrder(Node* root){
    if(root==NULL){
        return;
    }
    //L N R
    //L
    inOrder(root->left);
    cout<<root->data<<"";
    inOrder(root->right);
}
void postOrder(Node* root){
    if(root==NULL){
        return ;
    }
    //L R N
    //L
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<"";
}
void levelOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* front=q.front();
        q.pop();
        if(front==NULL){
            cout<<endl;
            if(!q.empty()){
            q.push(NULL);}
            

        }
        else{
            cout<<front->data<<"";
            if(front->left!=NULL){
                q.push(front->left);
            }
            if(front->right!=NULL){
                q.push(front->right);
            }

        }
    }


}
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftHeight=height(root->left);
    int rightHeight=height(root->right);
    int height=max(leftHeight, rightHeight)+1;
    return height;


}
int diameterOfBinaryTree(Node* root){
    if(root==NULL){
        return 0;
    }
    int option1=diameterOfBinaryTree(root->left);
    int option2=diameterOfBinaryTree(root->right);
    int option3=height(root->left)+height(root->right);
    int diameter=max(option1, max(option2, option3));
    return diameter;
}
int main(){
    Node* root=createNode();
    cout<<"printing preOrder";
    preOrder(root);cout<<endl;
    cout<<"printing InOrder";
    inOrder(root);cout<<endl;
    cout<<"printing postOrder";
    postOrder(root);cout<<endl;
    levelOrderTraversal(root);


    return 0;
}