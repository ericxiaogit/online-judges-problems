#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
char A[100];
using namespace std;
int main()
{
    char p;
    string a,t;
    int num,top,i,N,j,sen,yn;
    while(cin >> a)
    {
        sen = 0;
        top = a.length();
        yn = 1;
        while(top --)
        {
            if(a[top] >= 'p' && a[top] <='z')
            {
                sen++;
            }
            else if(a[top] == 'N')
            {
                if(sen == 0)
                {
                    yn = 0;
                    break;
                }
            }
            else if(a[top] == 'C' || a[top] == 'D' || a[top] == 'E' || a[top] == 'I' )
            {
                if(sen < 2)
                {
                    yn = 0;
                    break;
                }
                sen -= 1;
            }
            //cout << a[top] << ' ' <<sen << endl;
        }
        //cout << sen << endl;
        if(sen == 1 && yn == 1)
            cout << "YES" << endl;
        else
            cout << "NO" <<endl;

    }

}



