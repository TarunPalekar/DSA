#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }

};
Node* createTree(){
    cout<<"Enter the value";
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    //node ke data ka input le liya
    //aur ek node ke data me set kar diya
    Node* root=new Node(data);
    //ek node hum ne banae baki ki node recursion banake dega
    root->left=createTree();
    //root ke right ka tree pura recursion dege
    root->right=createTree();
    return root;

}
void preOrder(Node* root){
    //N L R
    if(root==NULL)
    {
        return ;
    }
    //N
    cout<<root->data<<"";
    //L
    preOrder(root->left);
    //R
    preOrder(root->right);
}
void inOrder(Node* root){
    if(root==NULL)
    {
        return;
    }
    //L N R
    inOrder(root->left);

    //N
    cout<<root->data<<"";
    //R
    inOrder(root->right);

}

void postOrder(Node* root){
    if(root==NULL){
        return ;
    
}
//L R N
//L
postOrder(root->left);
//R
postOrder(root->right);
//N
cout<<root->data<<"";
}

void levelOrderTraversal(Node* root){
    if(root==NULL)
    {
        cout<<"does not have a valid node";
        return;
        
    
    }
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node* front=q.front();
        q.pop();
    
        if(front==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<front->data;
            //insert left child
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



int main()
{
    Node* root=createTree();
    cout<<"printing preOrder of tree";
    cout<<endl;preOrder(root);cout<<endl;
    cout<<"printing Inorder of tree";
    cout<<endl;inOrder(root);cout<<endl;
    cout<<"printing postOrder of tree";
     cout<<endl;postOrder(root);cout<<endl;
     cout<<"printing level order treversal";
     cout<<endl;levelOrderTraversal(root);cout<<endl;
     cout<<"printing the height of the tree"<<height(root);

    return 0;
    //10 20 -1 -1 30 -1 -110 20 -1 -1 30 -1 -1
}