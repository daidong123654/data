/*    �ڶ���
    ʵ��2.1 : ʵ��˳���Ļ���������㷨��
    ����ʵ��˳���*/
#include<iostream>
#include<malloc.h>
#define MAX 100
using namespace std;
typedef char ElemType;
typedef struct Sqlist             //˳�����
{
    ElemType elem [MAX];
    int length;
};
void InitList(Sqlist *&L)           //˳����ʼ��
{
    L = (Sqlist *)malloc( sizeof(Sqlist) );
    L->length =0;
}
void DeleteList(Sqlist *&L)    //ɾ���ڵ�
{
    free(L);
}
int ListEmpty(Sqlist *&L)      //�ж϶ӿ�
{
   return (L->length==0);
}
int ListLength(Sqlist *&L)     //����������
{
    return (L->length);
}
void DisplayList(Sqlist *&L)
{
    int i;
    if(ListEmpty(L))
        return ;
    for(i=0;i<L->length;i++)
    {
        cout << L->elem[i] <<" ";
    }
    cout << endl;
}
int GetElem (Sqlist *L,int i,ElemType &e)          //�õ���i��Ԫ��
{
    if(i<1 || i>L->length)
        return 0;
    e = L->elem[i-1];
    return 1;
}
int LocateElem(Sqlist *L,ElemType e)
{
    int i = 0;
    while(i<L->length && L->elem[i] != e)   i++;
    if(i >= L->length)
        return 0;
    else
        return i+1;
}
int ListInsert(Sqlist *&L,int i,ElemType e)
{
    int j;
    if(i<1 || i>L->length+1)
        return 0;
    i--;
    for(j=L->length;j>i;j--)
        L->elem[j]=L->elem[j-1];
    L->elem[i] = e;
    L->length++;
    return 1;
}
int ListDelete(Sqlist *&L, int  i,ElemType &e)
{
    int j;
    if(i<1 || i>L->length)
        return 0;
    i--;
    e = L->elem[i];
    for (j=i; j<L->length-1;j++)
        L->elem[j] = L->elem[j+1];
    L->length--;
    return 1;
}
int main()
{
    Sqlist *L;
    ElemType e;
    InitList(L);

    ListInsert(L,1,'a'); DisplayList(L);
    ListInsert(L,2,'b'); DisplayList(L);
    ListInsert(L,3,'c'); DisplayList(L);
    ListInsert(L,4,'d'); DisplayList(L);
    ListInsert(L,5,'e'); DisplayList(L);
    ListInsert(L,6,'f'); DisplayList(L);
    ListInsert(L,1,'a'); DisplayList(L);
    ListInsert(L,2,'b'); DisplayList(L);
    ListInsert(L,3,'c'); DisplayList(L);
    ListInsert(L,4,'d'); DisplayList(L);
    ListInsert(L,5,'e'); DisplayList(L);
    DisplayList(L);
    cout << "˳����ȣ�"  << ListLength(L) <<endl;
    cout << "˳���L��" << (ListEmpty(L)?"��":"�ǿ�") <<endl;
    GetElem(L,3,e);
    cout << "˳���L�ĵ�3��Ԫ���ǣ�" << e <<endl;
    cout << "Ԫ��a��λ��Ϊ��" << LocateElem(L,'a') <<endl;
    cout << "�ڵ��ĸ�λ�ò���Ԫ��n \n";
    ListInsert(L,4,'n');
    cout << "���˳���";
    DisplayList(L);
    cout << "ɾ��������Ԫ�أ�\n";
    ListDelete(L,3,e);
    cout << "���˳���";
    DisplayList(L);
    cout << "�ͷ�˳���";
    DeleteList(L);
    DisplayList(L);
}
