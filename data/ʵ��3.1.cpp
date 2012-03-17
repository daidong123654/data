/*ʵ��3.1��ʵ��˳��ջ�ĸ��ֻ���������㷨*/
#include<iostream>
#include<malloc.h>
#define MAX 100
using namespace std;
typedef char ElemType;
typedef struct
{
    ElemType elem[MAX];
    int top;
}SqStack;
void InitStack(SqStack *&s)
{
    s=(SqStack *)malloc(sizeof(SqStack));
    s->top=-1;
}
void ClearStack(SqStack *&s)
{
    free(s);
}
int StackLength(SqStack *s)
{
    return (s->top + 1);
}
int StackEmpty(SqStack *s)
{
    return (s->top== -1);
}
int Push(SqStack *&s,ElemType e)
{
    if(s->top==MAX-1)
        return 0;
    s->top++;
    s->elem[s->top]=e;
    return 1;
}
int Pop(SqStack *&s,ElemType &e)
{
    if(s->top==-1)
        return 0;
    e=s->elem[s->top];
    s->top--;
    return 1;
}
int GetTop(SqStack *s,ElemType &e)
{
    if(s->top==MAX-1)
        return 0;
    e=s->elem[s->top];
    return 1;
}
void DispStack(SqStack *s)
{
    int i;
    for(i=s->top;i>=0;i--)
        cout << s->elem[i] << " ";
    cout << endl;
}
int main()
{
    ElemType e;
    SqStack *s;
    cout << "(1)��ʼ��ջs��\n";
    InitStack(s);
    cout <<"(2)ջΪ" << (StackEmpty(s)?"��":"�ǿ�") << endl;
    cout << "(3)˳�����abcde \n";
    Push(s,'a');
    Push(s,'b');
    Push(s,'c');
    Push(s,'d');
    Push(s,'e');
    cout <<"(4)ջΪ:  " << (StackEmpty(s)?"��":"�ǿ�") << endl;
    cout << "(5)ջ����Ϊ: ";
    cout << StackLength(s) <<endl;
    cout << "(6)��ջ��ջ��Ԫ������Ϊ�� ";
    DispStack(s);
    cout << "(7)��ջ����:";
    while(!StackEmpty(s))
    {
        Pop(s,e);
        cout << e <<" ";
    }
    cout << endl;
    cout << "(8)ջΪ��" << (StackEmpty(s)?"��":"�ǿ�") << endl;
    cout <<"(9)�ͷ�ջ\n";
    ClearStack(s);
}
/*This is the end of code!
2010/2/7/18:07*/
