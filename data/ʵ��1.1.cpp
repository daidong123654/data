/* *************������********************************* */
/*���һ�����������С��ΪN��������Ҫ��
    1:ÿ�����ʮ��������
    2:�����ܲ��ý����㷨��  */
#include<iostream>
#include<math.h>
using namespace std;
int prime(int n)
{
    int in;
    for (in=2;in<sqrt(n);in++)
    {
        if(n%in == 0)
            return 0;
    }
        return 1;
}
int main()
{
    int i;
    int j=0;
    int n =0;
    cout <<" n: ";
    cin >> n;
    cout <<"С��n��������\n";

    for(i=1;i<=n;i++)
    {
        if(i<=2)
        {
            cout<<i<<" ";
            j++;
        }
        else if(prime(i)==1)
        {
            cout<<i<<" ";
            j++;
        }
        if(j!=0 && ++j%10==0)
                cout<<endl;
    }

}
