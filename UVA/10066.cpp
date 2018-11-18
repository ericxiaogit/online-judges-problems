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
    long long int N;
    long long int now,temp;
    int a,b;
    now = 3;
    temp = 0;
    while(cin >> a >> b)
    {
            if(a == 0 && b == 0)
                break;
            temp ++;
            for(j = 1;j <= a;j++)
            {
                 cin >> A[0][j];
            }
            for(k = 1;k <= b;k++)
            {
                 cin >> A[k][0];
            }
            now = 0;
            for(j = 1;j <= a;j++)
            {
                 A[1][j] = now;
                 if(A[0][j] == A[1][0])
                    now = 1;
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
            cout << "Twin Towers #" << temp << endl;
            cout << "Number of Tiles : " << A[b][a] << endl << endl;




    }
}

