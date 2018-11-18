#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
long long int A[100 + 5];
int temp;
int main()
{
    //string a;
    int num,i,how,nows,j,a,big,print,b,k;
    int flag;
    int N,M;
    string fron,bac;
    string trash;
    int H,U,D,F;
    double height,now,minu;
    int day;
    while(cin >> H >> U >> D >> F)
    {
        flag = 0;
        if(H == 0)
            break;
        height = 0;
        minu = U * F / 100.000000;
        now = U;
        day = 0;
        while(1)
        {
            day ++;
            height += now;
            if(height > H)
            {
                flag = 1;
                break;
            }
            height -= D;
            if(height < 0)
            {
                flag = 0;
                break;
            }
            now = now - minu;
            if(now < 0)
                now = 0;
        }
        if(flag == 1)
            printf("success on day %d\n",day);
        else
            printf("failure on day %d\n",day);
    }


}

