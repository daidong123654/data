/*ʵ��5.1����5x5����������*/
#include<iostream>
#define MAX 10
using namespace std;
void fun(int a[MAX][MAX],int n)
{
    int i,j,k=0,m;
    if(n%2==0)
        m=n/2;
    else
        m=n/2+1;
    for(i=0;i<m;i++)
    {
        for(j=i;j<n-i;j++)
        {
            k++;
            a[i][j]=k;
        }
        for(j=i+1;j<n-i;j++)
        {
            k++;
            a[j][n-i-1]=k;
        }
        for(j=n-i-2;j>=i;j--)
        {
            k++;
            a[n-i-1][j]=k;
        }
        for(j=n-i-2;j>=i+1;j--)
        {
            k++;
            a[j][i]=k;
        }
    }
}
int main()
{
    int n,j,i;
    int a[MAX][MAX];
    cout<<"����n:(<10)   ";
    cin>>n;
    fun(a,n);
    cout<<"\n"<<n<<"�׷������£�\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<" \t"<<a[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

