#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
long long int A[100][100];
int main()
{
    //string a;
    long long int num,N,i,how,temp,nows,j,big,print,ans,x,y;
    long long int c,d;
    string str;
    x = 0;
    for(i = 1;i <= 51;i++)
    {
        A[i][1] = 1;
        //cout << A[i][1] << " ";
        for(j = 2;j <= i;j++)
        {
            if(j == 1)
                A[i][j] = 1;
            else
            {
                A[i][j] = A[i-1][j-1] + A[i-1][j];
            }
            //cout << A[i][j] << " ";

        }
        //cout << endl;
    }
    string a,b;
    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            a = "";
            b = "";
            cin >> str;
            j = 1;
            while(str[j] != '+')
            {
                a = a + " ";
                a[a.length()-1] = str[j];
                j++;
            }
            j++;
            while(str[j] != ')')
            {
                b = b + " ";
                b[b.length()-1] = str[j];
                j++;
            }
            j++;
            j++;
            x = str[str.length()-1] - '0';
            if(str[str.length()-2] != '^')
            {
                x = (str[str.length()-2]  - '0') * 10 + x;
            }
            //cout << "a = " << a << endl;
            //cout << "b = " << b << endl;
            temp = 0;
            cout << "Case " << i+1 << ": ";
            if(x!=1)
                cout << a << "^" << x << "+";
            else
                cout << a << "+";
            for(j = x;j >= 2;j--)
            {
                cout << A[x+1][j] << "*";
                cout << a;
                if(j > 2)
                {
                    cout << "^" << j-1;
                }
                cout <<"*";
                cout << b;
                if(j < x)
                {
                    cout << "^" << x-(j-1);
                }
                cout << "+";

            }
            if(x!=1)
                cout << b << "^" << x << endl;
            else
                cout << b << endl;

            //cout << endl;
        }
    }
}

