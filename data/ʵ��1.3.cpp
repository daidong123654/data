/* �ж�һ�������Ƿ����*/
#include<iostream>
#include<string.h>
#define MAX 100
using namespace std;
int fun(char s[])
{
    int flag = 1;
    int i,j,slen = strlen(s);
    for(i=0,j=slen-1; i<j;i++,j++)
    {
        if(s[i]!=s[j])
        {
            flag = 0;
            break;
        }
    return flag;
    }
}

int main()
{
    char s[MAX];
    cout << "������һ���ַ���";
    scanf("%s",s);
    if(fun(s)==1)
        printf("%s�ַ����ǻ��ġ�\n",s);
    else
        printf("%s�ַ������ǻ��ġ�\n",s);
}
