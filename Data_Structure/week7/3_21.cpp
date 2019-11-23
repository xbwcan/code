#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int IsEmpty(int Stack[], int end);
int Top(int Stack[], int top);
int Pop(int Stack[], int &top, int &end);
int Push(int Stack[], int &top, int &end,int num);
int MakeEmpyt(int Stack[], int &top, int &end);
int main()
{
    int n;
    cin >> n;
    int *Stack;
    Stack = new int[n];
    for (int i = 0; i < n; i++)
        Stack[i] = 0;
    int end1 = 0, end2 = n - 1;
    int top1 = 0, top2 = n - 1;
}
int IsEmpty(int Stack[], int end)
{
    if(Stack[end])
        return 1;
    else
        return 0;
}
int Top(int Stack[], int top)
{
    return Stack[top];
}
int Pop(int Stack[], int &top, int &end)
{
    int num = Stack[top];
    if(top>end)
        top--;
    else if(top<end)
        top++;
    else
        cout << "The Stack is empty!" << endl;
    return num;
}
int Push(int Stack[], int &top, int &end, int num)
{
    int j = 0;
    if(end==0)
    {
        j = 1;
        if(Stack[top+1])
        {
            cout << "The stack is full!" << end;
            return 0;
        }
    }
    else 
    {
        j = -1;
        if(Stack[top-1])
        {
            cout << "The stack is full!" << end;
            return 0;
        }
    }
    top += j;
    Stack[top] = num;
    return 0;
}
int MakeEmpyt(int Stack[], int &top, int &end)
{
    if(top==end)
    {
        cout << "It is already empyt!" << endl;
        return 0;
    }
    int j = 0;
    if(end==0)
        j = -1;
    else 
        j = 1;
    while(top!=end)
    {
        Stack[top] = 0;
        top += j;
    }
    Stack[top] = 0;
    return 0;
}