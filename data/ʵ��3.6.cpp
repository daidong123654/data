/*ʵ��3.6�����˾Ϳ���ģ�����*/
#include<iostream>
#include<malloc.h>
using namespace std;
typedef struct qnode
{
    int data;
    struct qnode *next;
} QNode;
typedef struct
{
    QNode *front,*rear;
} QuType;
void SeeDoctor()
{
    int sel,flag=1,find,no;
    QuType *qu;
    QNode *p;
    qu=(QuType *)malloc(sizeof(QuType));
    qu->front=qu->rear=NULL;
    while(flag==1)
    {
        cout <<"1:�Ŷ� 2������ 3���鿴�Ŷ� 4�������Ŷӣ��������ξ��� 5���°�  ��ѡ��  ";
        cin >> sel;
        switch(sel)
        {
        case 1:
            cout<<" << ���벡��\n";
            do
            {
                cin>>no;
                find=0;
                p=qu->front;
                while(p!=NULL&&!find)
                {
                    if(p->data==no)
                        find=1;
                    else
                        p=p->next;
                }
                if(find)
                    cout<<">>���벡���ظ�����������: ";
            }
            while(find==1);
            p=(QNode *)malloc(sizeof(QNode));
            p->data=no;
            p->next=NULL;
            if(qu->rear==NULL)
            {
                qu->front=qu->rear=p;
            }
            else
            {
                qu->rear->next=p;
                qu->rear=p;
            }
            break;
        case 2:
            if(qu->front==NULL)
                cout << ">>û��Ҫ�ҵĲ��ˣ�\n";
            else
            {
                p=qu->front;
                cout <<"����"<<p->data<<"����\n";
                if(qu->rear==p)
                {
                    qu->front=qu->rear=NULL;
                }
                else
                {
                    qu->front=p->next;
                }
                free(p);
            }
            break;
        case 3:
            if(qu->front==NULL)
                cout<<">>û�����еĲ��ˣ�\n";
            else
            {
                p=qu->front;
                cout << "�ŶӲ���:";
                while(p!=NULL)
                {
                    cout<<p->data<<" ";
                    p=p->next;
                }
                cout <<endl;
            }
            break;
        case 4:
            if(qu->front==NULL)
                cout<<">>û���ŶӵĲ��ˣ�\n";
            else
            {
                p=qu->front;
                cout << ">>���˰�����˳����";
                while(p!=NULL)
                {
                    cout<<p->data<<" ";
                    p=p->next;
                }
                cout <<endl;
            }
            flag=0;
            break;
        case 5:
            if(qu->front!=NULL)
                cout<<">>���ŶӵĲ��������ҽ��\n";
            flag=0;
            break;
        }
    }
}
int main()
{
    SeeDoctor();
}
