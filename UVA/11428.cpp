#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
int value[1005];
int ans[50000+5];
int main()
{
    //x^3 - y^3 = (x - y)(x^2 + xy + y^2)
    long long int i,j,T,k,big;
    long long int N,G;
    long long int now;
    int tempx,tempy;
    int ansx,ansy;
    int a,b;
    int half,sum;
    int flag;
    while(cin >> N)
    {
         if(N == 0) break;
         flag = 0;
         for(i = floor(sqrt(N));i >= 1;i--)
         {
             if(N % i != 0) continue;
             b = i;
             a = N/i;
             tempy = ((0 - b) - sqrt(b * b + 4 * (a - b * b)/3))/2;
             tempx = b + tempy;
             if(tempx * tempx * tempx - tempy * tempy * tempy == N && tempx > 0 && tempy > 0)
             {
                 ansx = tempx;
                 ansy = tempy;
                 flag = 1;
                 break;
             }
             tempy = ((0 - b) + sqrt(b * b + 4 * (a - b * b)/3))/2;
             tempx = b + tempy;
             if(tempx * tempx * tempx - tempy * tempy * tempy == N && tempx > 0 && tempy > 0)
             {
                 ansx = tempx;
                 ansy = tempy;
                 flag = 1;
                 break;
             }
         }
         if(flag == 1)
            cout << ansx << " " << ansy << endl;
        else
            cout << "No solution" << endl;



    }
}

