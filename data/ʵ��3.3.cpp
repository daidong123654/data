#include<iostream>
#include<malloc.h>
#define MAX 10
using namespace std;
typedef char ElemType;
typedef struct
{
    ElemType elem[MAX];
    int front,rear;
}SqQueue;
void InitQueue(SqQueue *&q)
{
    q=(SqQueue *)malloc(sizeof(SqQueue));
    q->front=q->rear=0;
}
void ClearQueue(SqQueue *&q)
{
    free(q);
}
int QueueEmpty(SqQueue *q)
{
    return (q->front==q->rear);
}
int QueueLength(SqQueue *q)
{
    return (q->rear - q->front +MAX) % MAX;
}
int enQueue(SqQueue *&q,ElemType e)
{
    if((q->rear+1)%MAX==q->front)
        return 0;
    q->rear=(q->rear+1)%MAX;
    q->elem[q->rear]=e;
    return 1;
}
int deQueue(SqQueue *q,ElemType &e)
{
    if(q->front==q->rear)
        return 0;
    q->front=(q->front+1)%MAX;
    e=q->elem[q->front];
    return 1;
}
int main()
{
    ElemType e;
    SqQueue *q;

    cout << "(1)��ʼ������q��\n";
    InitQueue(q);
    cout <<"(2)����Ϊ�� " << (QueueEmpty(q)?"��":"�ǿ�") << endl;
    cout << "(3)˳�����abcde \n";
    enQueue(q,'a');
    enQueue(q,'b');
    enQueue(q,'c');
    cout <<"(4)����Ϊ�� " << (QueueEmpty(q)?"��":"�ǿ�") << endl;
    if(deQueue(q,e)==0)
        cout << "����Ϊ�գ����ܳ��ӣ�\n ";
    else
        cout<<"(5)����һ��Ԫ��:   "  << e <<endl;
    cout << "(6)�������Ԫ��def\n";
    enQueue(q,'d');
    enQueue(q,'e');
    enQueue(q,'f');
    cout << "(7)���е�Ԫ�ظ����ǣ�" << QueueLength(q)<<endl;



}
