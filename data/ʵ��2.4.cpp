/*ʵ��2.4��ʵ��ѭ������ĸ�������Ļ����㷨*/#include<iostream>
#include<malloc.h>
using namespace std;
typedef char ElemType;
typedef struct Lnode                //�ڵ�����
{
    ElemType data;
    struct Lnode *next;
}LinkList;
void InitList(LinkList *&L)         //��ʼ������
{
    L = (LinkList *)malloc(sizeof(LinkList));
    L->next = L;
}
void DestroyList(LinkList *&L)
{
    LinkList *p = L,*q = p->next;
    while(q != NULL)
    {
        free(p);
        p = q;
        q = q->next;
    }
    free(p);
}
int ListEmpty(LinkList *L)
{
    return (L->next == L);
}
int ListLength(LinkList *L)    //����������
{
    LinkList *p = L;
    int i = 0;
    while(p->next != L)
    {
        i++;
        p = p->next;
    }
    return i;
}
void DisplayList(LinkList *L)
{
    LinkList *p = L->next;
    while(p != L)
    {
        cout << p->data <<" ";
        p = p->next;
    }
    cout << endl;
}
int GetElem(LinkList *L, int i ,ElemType &e)
{
    int j = 0;
    LinkList *p;
    if(L->next != L)
    {
        if(i==1)
        {
            e = L->next->data;
            return 1;
        }
        else
        {
            p = L->next;
            while(j<i-1&&p!=L)
            {
                j++;
                p = p->next;
            }
            if(p==L)
                return 0;
            else
            {
                e = p->data;
                return 1;
            }
        }
    }
    else
        return 0;
}

int LocateElem(LinkList *L,ElemType e)
{
    LinkList *p = L->next;
    int n =1;
    while(p != L && p->data != e)
    {
        p = p->next;
        n++;
    }
    if(p==L)
        return 0;
    else
        return n;
}
int ListInsert(LinkList *&L,int i,ElemType e)
{
    int j = 0;
    LinkList *p = L,*s;
    if(p->next ==L || i==1)
    {
        s = (LinkList *)malloc(sizeof(LinkList));
        s->data = e;
        s->next = p->next;
        p->next = s;
        return 1;
    }
    else
    {
        p = L->next;
        while(j<i-2 && p !=L)
        {
            j++;
            p = p->next;
        }
        if(p == L)
            return 0;
        else
        {
            s = (LinkList *)malloc(sizeof(LinkList));
            s->data = e;
            s->next = p->next;
            p->next = s;
            return 1;
        }
    }
}
int ListDelete(LinkList *&L,int i,ElemType &e)
{
    int j = 0;
    LinkList *p = L, *q;
    if(L->next != L)
    {
        if(i==1)
        {
            q = L->next;
            L->next = q->next;
            free(q);
            return 1;
        }
        else
        {
            p = L->next;
            while(j<i-2&&p!=L)
            {
                j++;
                p = p->next;
            }
            if(p==L)
                return 0;
            else
            {
                q = p->next;
                p->next = q->next;
                free(q);
                return 1;
            }
        }
    }
    else
        return 0;
}

int main()
{
    LinkList *L;
    ElemType e;
    cout << "(1)��ʼ������L�� \n";
    InitList(L);
    cout << "(2)���뷨��������\n";
    ListInsert(L,1,'a');
    ListInsert(L,2,'b');
    ListInsert(L,3,'c');
    ListInsert(L,4,'d');
    ListInsert(L,5,'e');
    cout << "(3)���������L��";
    DisplayList(L);
    cout << "(4)��������: ";
    cout << ListLength(L) <<endl;
    cout << "(5)������L�ǣ�" << (ListEmpty(L)?"��":"�ǿ�") <<endl;
    GetElem(L,3,e);
    cout << "(6)������L�ĵ�����Ԫ���ǣ�" <<  e << endl;
    cout << "(7)Ԫ��a��λ���ǣ�" << LocateElem(L,'a') <<endl;
    cout << "(8)�ڵ��ĸ�λ�ò���Ԫ��f";
    ListInsert(L,4,'f');
    cout << "(9)�������L��";
    DisplayList(L);
    cout << "(10)ɾ��������Ԫ��\n";
    ListDelete(L,3,e);
    cout << "(11)���������L��";
    DisplayList(L);
    cout << "(12)�ͷŵ�����L��\n";
    DestroyList(L);
return 0;
}
