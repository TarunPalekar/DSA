#include <iostream>
#include <queue>
#include <map>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createTree()
{
    cout << "Enter the data";
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    Node *newNode = new Node(data);
    // create left subtree
    newNode->left = createTree();
    // create right subtree
    newNode->right = createTree();
    return newNode;
}
void preOrderTraversal(Node *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data;
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void inOrderTraversal(Node *root)
{
    if (!root)
    {
        return;
    }
    // L N R
    inOrderTraversal(root->left);
    cout << root->data;
    inOrderTraversal(root->right);
}
void postOrderTraversal(Node *root)
{
    if (!root)
    {
        return;
    }
    // L R N
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data;
}
// void levelOrderTraversal(Node* root){
//  queue<Node*> q;
//  q.push(root);
//  q.push(NULL);

// while(!q.empty()){
//     Node* front=q.front();
//     q.pop();

//     if(front==NULL){

//         cout<<endl;
//         if(!q.empty()){
//         q.push(NULL);}
//     }
//     else{
//          cout<<front->data;
//          if(front->left){
//         q.push(front->left);
//     }
//     if(front->right){
//         q.push(front->right);
//     }
//     }

// }
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
    }
}
int findIndex(int inOrder[], int element, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (inOrder[i] == element)
        {
            return i;
        }
    }
    return -1;
}
Node *solve(int preOrder[], int inOrder[], int &preOrderIndex, int inOrderStart, int inOrderEnd, int size)
{
    if (preOrderIndex >= size || inOrderStart > inOrderEnd)
    {
        return NULL;
    }
    // ek case main solve karunga
    int element = preOrder[preOrderIndex];
    preOrderIndex++;
    Node *root = new Node(element);
    int position = findIndex(inOrder, element, size);
    root->left = solve(preOrder, inOrder, preOrderIndex, inOrderStart, position - 1, size);
    root->right = solve(preOrder, inOrder, preOrderIndex, position + 1, inOrderEnd, size);
    return root;
}
Node *postSolve(int postOrder[], int inOrder[], int &postOrderIndex, int inOrderStart, int inOrderEnd, int size)
{
    if (postOrderIndex < 0 || inOrderStart > inOrderEnd)
    {
        return NULL;
    }
    // ek case main solve karunga
    int element = postOrder[postOrderIndex];
    postOrderIndex--;
    Node *root = new Node(element);
    int position = findIndex(inOrder, element, size);
    // function call ko dekhe lena ek baar
    root->right = postSolve(postOrder, inOrder, postOrderIndex, position + 1, inOrderEnd, size);
    root->left = postSolve(postOrder, inOrder, postOrderIndex, inOrderStart, position - 1, size);

    return root;
}
void leftView(Node *root, int level, vector<int> &ans)
{
    if (!root)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }
    leftView(root->left, level + 1, ans);
    leftView(root->right, level + 1, ans);
}
void rightView(Node *root, int level, vector<int> &ans)
{
    if (!root)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }
    rightView(root->right, level + 1, ans);
    rightView(root->left, level + 1, ans);
}
void leftViewUsingLevelOrder(Node *root, vector<int> &ans)
{
    if (!root)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    bool ok = true;
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            if (ok == false)
            {
                ok = true;
            }
            if (q.empty())
            {
                break;
            }
            else
            {
                q.push(NULL);
            }
        }
        else
        {
            if (ok)
            {
                ans.push_back(front->data);
                ok = false;
            }
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
    }
}
void rightViewUsingLevelOrder(Node *root, vector<int> &ans)
{
    if (!root)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    bool ok = true;
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            if (ok == false)
            {
                ok = true;
            }
            if (q.empty())
            {
                break;
            }
            else
            {
                q.push(NULL);
            }
        }
        else
        {
            if (ok)
            {
                ans.push_back(front->data);
                ok = false;
            }

            if (front->right)
            {
                q.push(front->right);
            }
            if (front->left)
            {
                q.push(front->left);
            }
        }
    }
}
void topView(Node *root, vector<int> &ans)
{
    // sabse pehle map bana lo node aur vertical level ka
    // phir ek queue bana lo jisme pair dlaega node ka ur uske corres level ka
    // phir ek node nikal lo queue me se agar node ki value map me na ho to add akar do
    // phir uske left aur right child ko pair banake queue me dal do;
    // aur phir finnaly map ki seocnd value ko ans vector me save kara kar return kar do

    map<int, int> hdToNode;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node *, int> front = q.front();
        q.pop();
        Node *frontNode = front.first;
        int hd = front.second;
        if (hdToNode.find(hd) == hdToNode.end())
        {
            hdToNode[hd] = frontNode->data;
        }
        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }
    for (auto &i : hdToNode)
    {
        ans.push_back(i.second);
    }
}
void bottomView(Node *root, vector<int> &ans)
{
    // sabse pehle map bana lo node aur vertical level ka
    // phir ek queue bana lo jisme pair dlaega node ka ur uske corres level ka
    // bottom view me keval ek if conditon ko hata do
    //aur entire logic same rahega
    // phir uske left aur right child ko pair banake queue me dal do;
    // aur phir finnaly map ki seocnd value ko ans vector me save kara kar return kar do

    map<int, int> hdToNode;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node *, int> front = q.front();
        q.pop();
        Node *frontNode = front.first;
        int hd = front.second;

        hdToNode[hd] = frontNode->data;

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }
    for (auto &i : hdToNode)
    {
        ans.push_back(i.second);
    }
}

int main()
{
    // Node *root = createTree();
    // preOrderTraversal(root);
    // cout << endl;
    // inOrderTraversal(root);
    // cout << endl;

    // cout << endl;
    // levelOrderTraversal(root);
    // int preOrder[] = {2, 8, 10, 6, 4, 12};
    // int inOrder[] = {10, 8, 6, 2, 4, 12};
    // int preOrderIndex = 0;
    // int inOrderStart = 0;
    // int inOrderEnd = 5;
    // int size = 6;
    // Node *root = solve(preOrder, inOrder, preOrderIndex, inOrderStart, inOrderEnd, size);
    // cout << "printing the tree" << endl;
    // levelOrderTraversal(root);
    // cout << endl;
    // postOrderTraversal(root);
    // int postOrder[] = {10, 6, 8, 12, 4, 2};
    // int inOrder[] = {10, 8, 6, 2, 4, 12};
    // int postOrderIndex = 5;
    // int inOrderStart = 0;
    // int inOrderEnd = 5;
    // int size = 6;
    // Node *root = postSolve(postOrder, inOrder, postOrderIndex, inOrderStart, inOrderEnd, size);
    // cout << "printing the tree" << endl;
    // levelOrderTraversal(root);
    // cout << endl;
    // inOrderTraversal(root);
    Node *root = createTree();
    int level = 0;
    vector<int> ans;
    bottomView(root, ans);
    for (auto &i : ans)
    {
        cout << i << endl;
    }

    return 0;
}