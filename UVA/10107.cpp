#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
int A[10000];
int main()
{
    //string a;
    int num,N,i,how,temp,nows,j,a,big,print,b;
    temp = 0;
    while(cin >> N)
    {
        A[temp] = N;
        temp++;
        for(i = temp - 1;i > 0;i--)
        {
            if(N < A[i - 1])
            {
                swap(A[i],A[i - 1]);
            }
            else
                break;
        }
        //for(how = 0;how < temp;how++)
        //{
        //    cout << A[how] << " ";
        //}
        //cout << endl;
        if(temp % 2 == 0)
        {
            a = (temp)/2;
            b = (A[a - 1] + A[a]) / 2;
            cout << b << endl;
        }
        else
            cout << A[(temp + 1)/2 - 1]<< endl;

    }
}

