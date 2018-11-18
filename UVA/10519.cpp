#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
#define printf __mingw_printf
using namespace std;
int A[1000 + 5];
int M[100];
/*
string add(string a,string b)
{
    if(a.length() < b.length())
        swap(a,b);
    int i,flag;
    for(i = 0;i < a.length()-b.length();i++)
    {
        b = "0" + b;
    }
    string ans = "0" + a;
    a = "0" + a;
    b = "0" + b;
    flag = 0;
    for(i = a.length() - 1;i >= 0;i--)
    {
        ans[i] = a[i] + (b[i] - '0') + flag;
        if(ans[i] > '9')
        {
            ans[i] -= 10;
            flag = 1;
        }
        else
            flag = 0;

    }
    while(ans[0] == '0')
        ans.erase(0,1);
    return ans;

}*/
string minu1(string a)
{
    int i;
    a[a.length() - 1] -= 1;
    for(i = a.length()-1;i >= 0;i--)
    {
        if(a[i] < '0')
        {
            a[i] += 10;
            a[i-1] -= 1;
        }
        else
            break;
    }
    while(a[0] == '0')
        a.erase(0,1);
    return a;
}
string add2(string a)
{
    int i;
    a[a.length() - 1] += 2;
    a = "0" + a;
    for(i = a.length()-1;i >= 0;i--)
    {
        if(a[i] > '9')
        {
            a[i] -= 10;
            a[i-1] += 1;
        }
        else
            break;
    }
    while(a[0] == '0')
        a.erase(0,1);
    return a;
}
string time(string a,string b)
{
    int temp[2000];
    string ans;
    int i,j;
    for(i = 0;i < 500;i++)
    {
        temp[i] = 0;
    }

    for(i = a.length()-1;i >= 0;i--)
    {
        for(j = b.length()-1;j >= 0;j--)
        {
            temp[i+j + 1] += ((a[i]-'0')*(b[j]- '0'));
            //cout << (a[i]-'0')*(b[j]- '0') << endl;
            //system("pause");
            if(temp[i+j+1] > 9 && i + j +1 > 0)
            {
                temp[i+j] += (temp[i+j + 1])/10;
                temp[i+j + 1] = (temp[i+j + 1])%10 ;
            }
        }

    }
    int carry = 0;
    int flag = 0;
    for(i = a.length()+b.length() - 1;i >= 0;i--)
    {
        if(temp[i] > 9)
        {
            temp[i-1] += (temp[i])/10;
            temp[i] = (temp[i])%10 ;
        }

        flag = 1;
        ans = " " + ans;
        ans[0] = temp[i] + '0';
        //cout << temp[i] << " ";
    }
    while(ans[0] == '0')
        ans.erase(0,1);
    return ans;


}
int main()
{
    string M,N;
    string a,b,c;
    while(cin >> N)
    {
        while(N[0] == '0')
            N.erase(0,1);
        if(N == "")
        {
            cout << "1" << endl;
            continue;
        }
        else if(N == "1")
        {
            cout << "2" << endl;
            continue;
        }
        b = minu1(N);//b = n - 1
        a = time(N,b);
        c = add2(a);
        cout << c <<endl;
    }
}
