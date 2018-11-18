#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
int A[100000];
int B[100000];
int main()
{
    int SZ,P,i,x,y,temp;
    double t;
    while(cin >> SZ >> P)
    {
        if(SZ == 0 && P == 0) break;
        t = sqrt(P);
        temp = sqrt(P);
        if (t > temp)
            temp ++;
        if(temp % 2 == 0)
            temp ++;
        x = (temp+SZ)/2;
        y = x;
        //cout << y << " " << x << endl;         //(x,y) = temp^2
        for(i = 1;i <= temp * temp - P;i++)
        {
            if(i <= temp - 1)
                y--;
            else if(i <= (temp - 1)* 2)
                x--;
            else if(i <= (temp - 1)* 3)
                y++;
            else
                x++;
            //cout << y << " " << x << endl;

        }
        cout <<"Line = " << y << ", column = " <<x << "." <<endl;

    }
}

