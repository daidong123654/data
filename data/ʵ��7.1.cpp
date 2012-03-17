/*ʵ��7.1��ʵ�ֶ��������ֻ���������㷨*/
#include<iostream>
#include<malloc.h>
#define MAX 100
using namespace std;
typedef char ElemType;
typedef struct node
{
    ElemType data;
    struct node *lchild;
    struct node *rchild;
} BTNode;
void CreateBTNode(BTNode *&b,char *str)
{
    BTNode *st[MAX],*p=NULL;
    int top=-1,k,j=0;
    char ch;
    b=NULL;
    ch=str[j];
    while(ch != '\0')
    {
        switch(ch)
        {
        case '(':
            top++;
            st[top]=p;
            k=1;    //���ӽڵ�
            break;
        case ')':
            top--;        //����ƥ�䣬��ջ
            break;
        case ',':
            k=2;              //�Һ��ӽڵ�
            break;
        default:
            p = (BTNode *) malloc (sizeof(BTNode));
            p->data = ch;
            p->lchild = p->rchild = NULL;
            if(b == NULL)
                b = p;
            else
            {
                switch(k)
                {
                case 1:
                    st[top]->lchild = p;
                    break;
                case 2:
                    st[top]->rchild = p;
                    break;
                }
            }
        }
        j++;
        ch=str[j];
    }
}
BTNode *FindNode(BTNode *b,ElemType x)
{
    BTNode *p;
    if(b==NULL)
        return NULL;
    else if(b->data==x)
        return b;
    else
    {
        p=FindNode(b->lchild,x);
        if(p!=NULL)
            return p;
        else
            return FindNode(b->rchild,x);
    }
}
BTNode *lchilenode(BTNode *p)
{
    return p->lchild;
}
BTNode *rchildnode(BTNode *p)
{
    return p->rchild;
}
int BTNodedepth(BTNode *b)
{
    int lchildep;
    int rchildep;
    if(b==NULL)
        return 0;
    else
    {
        lchildep=BTNodedepth(b->lchild);
        rchildep=BTNodedepth(b->rchild);
        return (lchildep>rchildep)?(lchildep+1):(rchildep+1);
    }
}
int Display(BTNode *b)
{
    if(b!=NULL)
    {
        cout<<b->data;
        if(b->lchild!=NULL || b->rchild!= NULL)
        {
            cout<<"(";
            Display(b->lchild);
            if(b->rchild!=NULL)
                cout<<",";
            Display(b->rchild);
            cout<<")";
        }
    }
}
int BTwidth(BTNode *b)
{
    struct
    {
        int lno;
        BTNode *p;
    } qu[MAX];
    int front,rear;
    int lnum,ma,i,n;
    front =rear =0;
    if(b!=NULL)
    {
        rear++;
        qu[rear].p=b;
        qu[rear].lno=1;
        while(rear!=front)
        {
            front++;
            b=qu[front].p;
            lnum=qu[front].lno;
            if(b->lchild!=NULL)
            {
                rear++;
                qu[rear].p=b->lchild;
                qu[rear].lno=lnum+1;
            }
            if(b->rchild!=NULL)
            {
                rear++;
                qu[rear].p=b->rchild;
                qu[rear].lno=lnum+1;
            }
        }
        ma=0;
        lnum=1;
        i=1;
        while(i<=rear)
        {
            n=0;
            while(i<=rear&&qu[i].lno==lnum)
            {
                n++;
                i++;
            }
            lnum=qu[i].lno;
            if(n>ma) ma=n;
        }
        return ma;
    }
    else
        return 0;
}
int Nodes(BTNode *b)
{
    int num1,num2;
    if(b==NULL)
        return 0;
    else if(b->lchild==NULL&&b->rchild==NULL)
        return 1;
    else
    {
        num1=Nodes(b->lchild);
        num2=Nodes(b->rchild);
        return num1+num2+1;
    }
}
int Leafnodes(BTNode *b)
{
    int num1,num2;
    if(b==NULL)
        return 0;
     else if(b->lchild==NULL&&b->rchild==NULL)
        return 1;
    else
    {
        num1=Leafnodes(b->lchild);
        num2=Leafnodes(b->rchild);
        return num1+num2;
    }
}
int main()
{
    BTNode *b,*p,*lp,*rp;
    CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    cout<<"1�����������";
    Display(b);
    cout<<endl;
    cout<<"2H�ڵ�";
    p=FindNode(b,'H');
    if(p!=NULL)
    {
        lp=lchilenode(p);
        if(lp!=NULL)
        {
            cout<<"����Ϊ��"<<lp->data<<"    ";

        }
        else
            cout<<"�����ӣ�";
        rp=rchildnode(p);
        if(rp!=NULL)
        {
            cout<<"H�Һ���Ϊ��"<<rp->data;

        }
        else
            cout<<"H���Һ��ӣ�";
    }
    cout<<endl;
    cout<<"3��ȣ�"<<BTNodedepth<<endl;
    cout<<"4��ȣ�"<<BTwidth(b)<<endl;
    cout<<"5������"<<Nodes(b)<<endl;
    cout<<"6Ҷ�ӣ�"<<Leafnodes(b)<<endl;
}
