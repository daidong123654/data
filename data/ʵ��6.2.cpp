/*ʵ��6.2�����n�ʺ�����*/
#include<iostream>
#include<stdlib.h>
using namespace std;
const int N = 20;
int q[N];
int cont = 0;
void print(int n)
{
    cont++;
    int i;
    cout<<"��"<<cont<<"�����ǣ�";
    for(i=1;i<=n;i++)
    {
        cout<<q[i]<<" ";
    }
    cout<<endl;
}
int find(int i,int k)
{
    int j;
    j=1;
    while(j<k)
    {
        if((q[j]==i) || (abs(q[j]-i)== abs(j-k) ))
            return 0;
        j++;
    }
    return 1;
}
void place(int k,int n)
{
    if(k>n)
        print(n);
    else
        for(int i=1;i<=n;i++)
            if(find(i,k))
            {
                q[k]=i;
                place(k+1,n);
            }
}
int main()
{
    int n;
    cout<<"�ʺ����⣨n<20�� n = ";
    cin>>n;
    if(n>20)
        cout<<"ֵ̫�󣡲������!\n";
    else
    {
        cout<<n<<"�ʺ�����������£�\n";
        place(1,n);
        cout<<endl;
    }
}
