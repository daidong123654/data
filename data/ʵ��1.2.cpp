/* ��һ���������ĸ�λ֮��*/
#include<iostream>
using namespace std;
int fun(int num)
{
    int s = 0;
    while(num)
    {
        s += num % 10;
        num /= 10;
    }
    return s;
}
int main()
{
    int n;
    cout << endl;
    cout << "������һ����������";
    cin >> n;
    cout << "����λ֮��Ϊ��" << fun(n) << endl;
}
