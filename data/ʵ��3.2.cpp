/*ʵ��3.2��ʵ����ջ���ֻ���������㷨*/
#include<iostream>
#include<malloc.h>
using namespace std;
typedef char ElemType;
typedef struct Linknode
{
    ElemType data;
    struct Linknode *next;
}LiStack;
void InitStack(LiStack *&s)
{
    s=(LiStack *)malloc(sizeof(LiStack));
    s->next=NULL;
}
void ClearStack(LiStack *&s)
{
    LiStack *p=s->next;
    while(p!=NULL)
    {
        free(s);
        s=p;
        p=p->next;
    }
    free(p);
}
int StackLength(LiStack *s)
{
    int i=0;
    LiStack *p;
    p=s->next;
    while(p!=NULL)
    {
        i++;
        p=p->next;
    }
    return i;
}
int StackEmpty(LiStack *s)
{
    return (s->next==NULL);
}
void Push(LiStack *&s,ElemType e)
{
    LiStack *p;
    p = (LiStack *)malloc(sizeof(LiStack));
    p->data=e;
    p->next=s->next;
    s->next=p;
}
int Pop(LiStack *&s,ElemType e)
{
    LiStack *p;
    if(s->next==NULL)
        return 0;
    p=s->next;
    e=p->data;
    s->next=p->next;
    free(p);
    return 1;
}
int GetTop(LiStack *s,ElemType &e)
{
    if(s->next==NULL)
        return 0;
    e=s->next->data;
    return 1;
}
void DispStack(LiStack *s)
{
    LiStack *p=s->next;
    while(p!=NULL)
    {
        cout << p->data << " ";
        p=p->next;
    }
    cout << endl;
}
int main()
{
    ElemType e;
    LiStack *s;
    cout << "(1)��ʼ����ջs��\n";
    InitStack(s);
    cout <<"(2)��ջΪ�� " << (StackEmpty(s)?"��":"�ǿ�") << endl;
    cout << "(3)˳�����abcde \n";
    Push(s,'a');
    Push(s,'b');
    Push(s,'c');
    Push(s,'d');
    Push(s,'e');
    Push(s,'f');
    Push(s,'g');
    Push(s,'h');
    Push(s,'i');
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
    cout << "(8)ջΪ�� " << (StackEmpty(s)?"��":"�ǿ�") << endl;
    cout <<"(9)�ͷ�ջ\n";
    ClearStack(s);

}
