#include <iostream>
#include <stack>
using namespace std;
class Stack
{
public:
    int *arr;
    int size;
    int top1;
    int top2;
    Stack(int size)
    {
        this->size = size;
        this->arr = new int[size];

        this->top1 = -1;
        this->top2 = size;
    }
    void push1(int val)
    {
       //

        if (abs(top2 - top1 == 1))
        {
            cout << "stack overflow" << endl;
            return;
        }
         top1++;
        arr[top1] = val;
    }
    void push2(int val)
    {
        
        if (abs(top2 - top1 == 1))
        {
            cout << "stack overFlow"
                 << "isme error aa raha hai" << endl;
            return;
        }
        top2--;
        arr[top2] = val;
    }
    int pop1()
    {
        if (top1 < 0)
        {
            cout << "stack underflow" << endl;
            return -1;
        }
        int temp = arr[top1];
        arr[top1] = 0;
        top1--;
        return temp;
    }
    int pop2()
    {
        if (top2 >= size)
        {
            cout << "stack underflow" << endl;
            return -1;
        }
        int temp = arr[top2];
        arr[top2] = 0;
        top2++;
        return temp;
    }
    int getTop1Element()
    {
        if (top1 < 0)
        {
            return -1;
        }
cout<<"DFGHJK";
        return arr[top1];
    }
    int getTop2Element()
    {
        if (top2 == size)
        {
            return -1;
        }

        return arr[top2];
    }
    void printArray()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << endl;
        }
    }
};
using namespace std;
int main()
{
    Stack st(5); // creating obejct of class stack of size 5
    st.push1(1);
    st.push2(5);
    st.push1(3);
    st.push2(4);
    st.push1(2);
     st.push1(6);
      st.push1(6);
       st.push2(4);


    
    st.printArray();
    cout<<endl;
    int top = st.getTop2Element();
    cout<<top;

    return 0;
}