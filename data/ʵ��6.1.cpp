/*ʵ��6.1��������amk��2,1���ĵݹ����ֵ����*/
#include<iostream>
using namespace std;
int count=1;
int amk(int m,int n)
{
    int g,f;
    cout<<"\tamk("<<m<<","<<n<<")";
    if(count++%3==0)
        cout<<endl;
    if(m==0)
    {
        cout<<"\tamk(" << 0 << "," <<n << ")= " << n+1 ;
        if(count++%3==0)
            cout<<endl;
        return n+1;
    }
    else if(n==0)
    {
        f=amk(m-1,1);
        cout<<"\tamk(" << m-1 << "," <<1 << ")= " << f;
        if(count++%3==0)
            cout<<endl;
        return f;
    }
    else
    {
        g=amk(m,n-1);
        f=amk(m-1,g);
        cout<<"\tamk(" << m-1 << "," << g << ")= " << f ;
        if(count++%3==0)
            cout<<endl;
        return f;
    }
}
int main()
{
    int m=2,n=1;
    cout<<"��amk��"<<m<<","<<n<<"���Ĺ������£�\n";
    cout<< "\tamk("<<m<<","<<n<<")= "<<amk(2,1);
}
