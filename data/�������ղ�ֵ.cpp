#include<iostream>
#define MAX 100
using namespace std;
int main()
{
    double a,l=1.0,y=0.0;
    double x[MAX],fx[MAX];
    int k=0,n,i=0;
    cout<<"������n�β�ֵ��n: ";
    cin>>n;
    cout<<"������n�β�ֵ�� x[]: ";
    while(i<=n)
    {
        cin>>x[i];
        i++;
    }
    cout<<"������n�β�ֵ�� fx[]: ";
    i=0;
    while(i<=n)
    {
        cin>>fx[i];
        i++;
    }
    cout<<"������Ҫ��ֵ�� x: ";
    cin>>a;
    while(k<=n)
    {
        l=1.0;
        for(int j=0;j<=n;j++)
        {
            if(k!=j)
            {
                l=l*(a-x[j])/(x[k]-x[j]);
            }
        }
        y=y+l*fx[k];
        k++;
    }
    cout<<"("<<a<<","<<y<<")\n";
    cout<<"��������"<<a<<"����ֵ�ǣ�"<<y<<endl;
return 0;
}
