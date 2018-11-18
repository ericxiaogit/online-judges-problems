#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
int A[1000];
using namespace std;
int main()
{
    int sum;
    int a,b;
    int N,i,k,j;
    double avg,temp;
    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            sum = 0;
            cin >> k;
            for(j = 0;j < k;j++)
            {
                cin >> A[j];
                sum += A[j];
            }
            //cout << i << " " << sum <<" "<< k << endl;
            avg = sum/k;
            temp = 0;
            for(j = 0;j < k;j++)
            {
                if(A[j] > avg)
                    temp ++;
            }
            printf("%.3lf",temp*100/k);
            cout <<"%" << endl;

        }
    }

}



