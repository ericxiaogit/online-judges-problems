#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
long long int A[1000+5][1000+5];
int main()
{
    unsigned long long int i,j,T,k;
    long long int N,a,b;
    long long int now,temp;
    string x,y;
    now = 3;
    temp = 0;
    while(getline(cin,x))
    {
            if(x == "#") break;
            getline(cin,y);
            a = x.length();
            b = y.length();
            temp ++;
            //cout << temp << " :" << x << " ******* " << y << endl;
            for(j = 1;j <= a;j++)
            {
                 A[0][j]= x[j - 1];
                 //cout << A[0][j] << " ";
            }
            //cout << endl;
            for(k = 1;k <= b;k++)
            {
                 A[k][0] = y[k - 1];
                 //cout << A[k][0] << " ";
            }
            //cout << endl;
            now = 0;
            for(j = 1;j <= a;j++)
            {
                //cout << A[0][j] << " " << A[1][0] << endl;
                if(A[0][j] == A[1][0])
                    now = 1;
                 A[1][j] = now;
            }
            now = 0;
            for(k = 2;k <= b;k++)
            {
                if(now == 0 && A[k][0] == A[0][1])
                {
                    now = 1;
                    A[k][1] = A[k-1][1] + 1;
                }
                else
                    A[k][1] = A[k-1][1];

            }
            for(j = 2;j <= a;j++)
            {
                 for(k = 2;k <= b;k++)
                {
                     if(A[k][0] != A[0][j])
                        A[k][j] = max(A[k][j - 1],A[k-1][j]);
                     else
                        A[k][j] = A[k-1][j-1] + 1;
                }
            }
            /*
            for(j = 0;j <= a;j++)
            {
                 for(k = 0;k <= b;k++)
                {
                     if(A[k][j] < 10)
                        cout << " ";
                     cout << A[k][j] << " ";
                }
                cout << endl;
            }
            */
            cout << "Case #" << temp << ": you can visit at most " << A[b][a]<< " cities." <<endl;
            //cout << temp << ";ans = " << A[b][a] << endl;




    }
}

