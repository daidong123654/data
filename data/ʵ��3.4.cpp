/*ʵ��3.4��ʵ�����ӵĻ���������㷨*/
#include<iostream>
#include<malloc.h>
using namespace std;
typedef char ElemType;
typedef struct qnode
{
    char data;
    struct qnode *next;
}QNode;
typedef struct
{
    QNode *front;
    QNode *rear;
}LiQueue;
void InitQueue(LiQueue *&q)
{
    q=(LiQueue *)malloc(sizeof(LiQueue));
    q->front=q->rear=NULL;
}
void ClearQueue(LiQueue *&q)
{
    QNode *p=q->front,*r;
    if(p!=NULL)
    {
        r=p->next;
        while(r!=NULL)
        {
            free(p);
            p=r;
            r=p->next;
        }
    }
    free(q);
}
int QueueLength(LiQueue *q)
{
    int n=0;
    QNode *p=q->front;
    while(p!=NULL)
    {
        n++;
        p=p->next;
    }
    return n;
}
int QueueEmpty(LiQueue *q)
{
    if(q->rear==NULL)
        return 1;
    else
        return 0;
}
void enQueue(LiQueue *&q,ElemType e)
{
    QNode *s;
    s=(QNode *)malloc(sizeof(QNode));
    s->data=e;
    s->next=NULL;
    if(q->rear==NULL)
        q->front=q->rear=s;
    else
    {
        q->rear->next=s;
        q->rear=s;
    }
}
int deQueue(LiQueue *&q,ElemType e)
{
    QNode *t;
    if(q->rear==NULL)
        return 0;
    if(q->rear==q->front)
    {
        t=q->front;
        q->front=q->rear=NULL;
    }
    else
    {
        t=q->front;
        q->front=q->front->next;
    }
    e=t->data;
    free(t);
    return 1;
}
int main()
{
    ElemType e;
    LiQueue *q;
    cout<<"�����͵Ķ����Ѿ��������Ͳ��������Լ�Ϲ����";
}







