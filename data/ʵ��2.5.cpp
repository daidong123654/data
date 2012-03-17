/*ʵ��2.5��ʵ��ѭ��˫������ֻ���������㷨*/
#include<iostream>
#include<malloc.h>
using namespace std;
typedef char ElemType;
typedef struct DNode
{
    ElemType data;
    struct DNode *pre;
    struct DNode *next;
} DLinkList;
void InitList(DLinkList *&L)
{
    L = (DLinkList *)malloc(sizeof(DLinkList));
    L->pre = NULL;
    L->next= NULL;
}
void DestroyList(DLinkList *&L)
{
    DLinkList *p = L,*q = p->next;
    while(q != NULL)
    {
        free(p);
        p = q;
        q = p->next;
    }
    free(p);
}
int ListEmpty(DLinkList *L)
{
    return (L->next==L);
}
int ListLength(DLinkList *L)
{
    DLinkList *p=L;
    int i = 0;
    while(p->next != NULL)
    {
        i++;
        p = p->next;
    }
    return i;
}
void DisplayList(DLinkList *L)
{
    DLinkList *p = L->next;
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int GetElem(DLinkList *L,int i,ElemType &e)   //�õ���i��Ԫ��
{
    int j = 0;
    DLinkList *p;
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
int LocateElem(DLinkList *L,ElemType e)        //ȷ��Ԫ��e��λ��
{
    int n = 1;
    DLinkList *p = L->next;
    while(p!=NULL && p->data != e)
    {
        n++;
        p = p->next;
    }
    if (p==NULL)
        return 0;
    else
        return n;
}
int ListInsert(DLinkList *L,int i,ElemType e)
{
    int j = 0;
    DLinkList *p = L,*s;
    if(p->next ==L)
    {
        s = (DLinkList *)malloc(sizeof(DLinkList));
        s->data = e;
        p->next=s;
        s->next=p;
        p->pre=s;
        s->pre=p;
        return 1;
    }
    else if(i==1)
    {
        s = (DLinkList *)malloc(sizeof(DLinkList));
        s->data=e;
        s->next=p->next;
        p->next=s;
        s->next->pre=s;          //�������쳣��������ô�죡����
        s->pre=p;
        return 1;
    }
    else
    {
        p=L->next;
        while(j<i-2&&p!=L)
        {
            j++;
            p=p->next;
        }
        if(p==L)
            return 0;
        else
        {
            s=(DLinkList *)malloc(sizeof(DLinkList));
            s->data=e;
            s->next=p->next;
            if(p->next!=NULL)
                p->next->pre=s;
            s->pre=p;
            p->next=s;
            return 1;
        }
    }
}
int ListDelete(DLinkList *&L,int i,ElemType &e)
{
    int j = 0;
    DLinkList *p = L, *q;
    if(L->next != L)
    {
        if(i==1)
        {
            q = L->next;
            L->next = q->next;
            q->next->pre=L;
            free(q);
            return 1;
        }
        else
        {
            p = L->next;
            while(j<i-2&&p!=NULL)
            {
                j++;
                p = p->next;
            }
            if(p==L)
                return 0;
            else
            {
                q = p->next;
                if(q==NULL)
                    return 0;
                p->next = q->next;
                if(p->next!=NULL)
                    p->next->pre=p;
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
    DLinkList *L;
    ElemType e;
    cout << " (1)����ʼ��˫����L��\n ";
    InitList(L);
    cout << "(2):���β��ò��뷨����Ԫ��abcde\n";
    ListInsert(L,1,'a');
    ListInsert(L,2,'b');
    ListInsert(L,3,'c');
    ListInsert(L,4,'d');
    ListInsert(L,5,'e');
    cout << " (3)���˫����L�� ";
    DisplayList(L);
    cout << " (4)˫����ĳ��ȣ�";
    cout << ListLength(L) << endl;
    cout << " (5)˫����Ϊ:  " << (ListEmpty(L)?"��":"�ǿ�");
    GetElem(L,3,e);
    cout << " (6)˫�����3��Ԫ��Ϊ��" << e << endl;
    cout << " (7)Ԫ��a��λ����: " << LocateElem(L,'a') <<endl;
    cout << " (8)�ڵ��ĸ�λ���ϲ���Ԫ��f";
    ListInsert(L,4,'f');
    cout << " (9)���˫����L";
    DisplayList(L);
    cout << " (10)ɾ��������Ԫ�أ�\n";
    ListDelete(L,3,e);
    cout << " (11)���˫����L: ";
    DisplayList(L);
    cout << " (12)�ͷ�˫����L��";
}
