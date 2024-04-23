#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>
using namespace std;
// class Queue{
//     public:
//     int * arr;
//     int size;
//     int front;
//     int rear;
//     Queue(int size){
//         arr=new int[size];
//         this->size=size;
//         this->front=-1;
//         this->rear=-1;
//     }

//     void push(int data){
//     if(rear==size-1){
//         cout<<"Queue is Full"<<endl;

//     }
//     else if(front==-1&& rear==-1){
//         front++;
//         rear++;
//         arr[rear]=data;
//     }
//     else{
//         rear++;
//         arr[rear]=data;
//     }

// }
// void pop(){
//     if(front==-1&& rear==-1){
//         cout<< "queue is empty";
//     }
//     else if(front==rear){
//         arr[front]=-1;
//         front=-1;
//         rear=-1;

//     }
//     else{
//         arr[front]=-1;
//         front++;
//     }
// }
//  int frontElement(){
//     if(front==-1){
//         cout<<"queue is empty"<<endl;
//     }
//     return arr[front];
//  }
//  int rearElement(){
//     if(rear==-1){
//         cout<<"queue is empty"<<endl;

//     }
//     return arr[rear];
//  }
// bool isFull(){
//     if(rear==size-1){
//         return true;
//     }
//     else{
//         return false;
//     }
// }
// bool isEmpty(){
//     if(rear==-1&& front==-1){

//         return true;
//     }
//     else{
//         return false;

//     }
// }

// };
void reverseQueue(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    int front = q.front();
    q.pop();
    reverseQueue(q);
    q.push(front);
    //     stack<int> s;
    //     while(!q.empty()){
    //         s.push(q.front());
    //         q.pop();
    //     }
    //     while(!s.empty()){
    //         q.push(s.top());
    //         s.pop();
    //     }
}
void interleaveQueue(queue<int> &q)
{
    queue<int> q2;
    int n = q.size();

    if (n % 2 == 0)
    {
        n = n / 2;
    }
    else
    {
        n = (n / 2) + 1;
    }
    int k = n;
    while (k--)
    {
        q2.push(q.front());
        q.pop();
    }
    while (!q2.empty())
    {
        q.push(q2.front());
        q2.pop();
        int front = q.front();
        q.pop();
        q.push(front);
    }
}
void reverseKElement(queue<int> &q, int k)
{
    stack<int> st;
    int n = k;
    while (n--)
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    n = q.size();
    int remaining = n - k;
    while (remaining--)
    {
        int front = q.front();
        q.push(front);
        q.pop();
    }
}
void firstNonRepeatingCharacter(vector<char> &ch, vector<char> &ans)
{

    queue<char> q;
    map<char, int> mp;
    for (int i = 0; i < ch.size(); i++)
    {
        char element = ch[i];
        mp[element]++;
        q.push(element);
        while (!q.empty())
        {
            char frontEle = q.front();
            if (mp[frontEle] > 1)
            {
                q.pop();
            }
            else
            {
                ans.push_back(frontEle);
                break;
            }
        }
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
}

int main()
{
    vector<char> ch = {'a', 'b', 'a', 'b', 'c'};
    vector<char> ans;
    firstNonRepeatingCharacter(ch, ans);
    cout << ans.size();
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    //    Queue q(10);
    //     q.push(10);
    //     q.push(20);
    //     if(q.isEmpty())
    // {
    //     cout<<"queue is empty"<<endl;
    // }
    // else{
    //     cout<<"queue is not empty"<<endl;
    // };
    // cout<<q.frontElement();
    // cout<<q.rearElement();

    // queue<int> q;
    // q.push(10);
    // q.push(20);
    // q.push(30);
    // q.push(40);
    // q.push(50);
    // q.push(60);
    // // reverseQueue(q);
    // // int k = 2;
    // // reverseKElement(q, k);
    // interleaveQueue(q);
    // while (!q.empty())
    // {
    //     cout << q.front() << " ";
    //     q.pop();
    // }

    return 0;
}