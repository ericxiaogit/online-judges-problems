#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
int A[4];
int B[100000];
int main()
{
    int SZ,P,i,j,x,y,temp,k,a,b,N;
    double t;
    a = 1;
    N = 0;

    cin >> P;
    for(i = 0;i < P;i++)
    {
        temp = 0;
        for(j = 0;j < 4;j++)
        {
            cin >> A[j];
            temp += A[j];
        }
        sort(A,A+4);
        //cout << A[0] << " " << A[1] << " " << A[2] << " " << A[3] << endl;
        if(A[0] == A[1] && A[1] == A[2] && A[2] == A[3])
            cout << "square" << endl;
        else if(A[0] == A[1] && A[2] == A[3])
            cout << "rectangle" << endl;
        else
        {
            a = 0;
            for(j = 0;j < 4;j++)
            {
                if(A[j] > temp - A[j])
                {
                    a = 1;
                    break;
                }
            }
            if(a == 1)
                cout << "banana" << endl;
            else
                cout << "quadrangle" << endl;
        }

    }

}


