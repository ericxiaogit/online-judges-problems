#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
    int i,c,d,j,t,big,K;
    t = 0;
    int rolls,cig,ans;
    int a,b;
    int temp;
    int T;
    int sum;
    int last1,last2;
    temp = 0;
    cin >> T;
    for(i = 0;i < T;i++)
    {
        cin >> K;
        a = 1;
        b = K;
        while(a < b)
        {
            cout << "Test";
            if((b - a + 1) % 3 == 0)
            {
                for(j = 0;j < 2*(b-a+1)/3;j++)
                {
                    cout << " " << a+j;
                    if(j == (b-a+1)/3 - 1)
                        last1 = a+j;
                    else if(j == 2*(b-a+1)/3 - 1)
                        last2 = a+j;
                }
            }
            else if((b - a + 1) % 3 == 1)
            {
                for(j = 0;j < 2*(b-a)/3;j++)
                {
                    cout << " " << a+j;
                    if(j == (b-a)/3 - 1)
                        last1 = a+j;
                    else if(j == 2*(b-a)/3 - 1)
                        last2 = a+j;
                }
            }
            else
            {
                for(j = 0;j < 2*(b- a + 2)/3;j++)
                {
                    cout << " " << a+j;
                    if(j == (b-a+2)/3 - 1)
                        last1 = a+j;
                    else if(j == 2*(b-a+2)/3 - 1)
                        last2 = a+j;
                }
            }
            cout << endl;
            fflush(stdout);
            cin >> c;
            if(c == 0)
            {
                a = last2 + 1;
            }
            else if(c == 1)
            {
                b = last1;
            }
            else
            {
                b = last2;
                a = last1 + 1;
            }

        }
        cout << "Answer " << b << endl;
        fflush(stdout);
    }


}

