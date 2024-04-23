#include <iostream>
#include <stack>
using namespace std;
string reverseString(string &str)
{
    stack<char> ch;
    for (auto i : str)
    {
        ch.push(i);
    }
    string temp = "";
    while (!ch.empty())
    {
        temp = temp + ch.top();
        ch.pop();
    }
    return temp;
}
void solve(stack<int> &st, int &pos, int &ans)
{
    if (pos == 1)
    {
        cout << "Deleting " << st.top() << endl;
        ans = st.top();
        st.pop();
        return;
    }

    // ek case main solve karunga
    pos--;
    int temp = st.top();
    st.pop();
    solve(st, pos, ans);
    st.push(temp);
}
int getMiddleElement(stack<int> &st)
{
    int n = st.size();
    if (n == 0)
    {
        cout << "stack is empty no middle element" << endl;
        return -1;
    }
    else
    {
        int pos = 0;
        int ans = -1;
        if (n % 2 == 1)
        {
            // odd size ka case
            pos = (n / 2) + 1;
        }
        else
        {
            pos = n / 2;
        }
        solve(st, pos, ans);
        return ans;
    }
}
void insertAtBottom(stack<int> &st, int val)
{
    if (st.empty())
    {
        st.push(val);
        return;
    }
    int temp = st.top();
    st.pop();
    insertAtBottom(st, val);
    st.push(temp);
}
void reverseStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int temp = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, temp);
}
void insertSorted(stack<int> &st, int val)
{
    if (st.empty() || val > st.top())
    {
        st.push(val);
        return;
    }
    int temp = st.top();
    st.pop();
    insertSorted(st, val);
    st.push(temp);
}
void sortStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int temp = st.top();
    st.pop();
    sortStack(st);
    insertSorted(st, temp);
}



int main()
{
    stack<int> st;

    st.push(10);
    st.push(40);

    st.push(30);
    st.push(20);
    st.push(50);
    // int element=100;
    // insertAtBottom(st, element);
    // int element = 35;
    // insertSorted(st, element); 67
  //  sortStack(st);

    // int mid=getMiddleElement(st);
    // cout<<mid<<endl;
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    // string str="Tarun";
    // string temp=reverseString(str);
    // cout<<temp;

    return 0;
}