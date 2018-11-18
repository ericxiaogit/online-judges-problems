#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
int A[100000 + 50];
int coun[30 + 5];

int main()
{
    int sum,P,i,j,k;
    double t;
    int even,odd,evans;
    int trash,temp;
    long long int W , N,M;
    int day,month,year,qy;
    trash = 0;
    int zero;
    int flag;
    int n,m;
    int a;
    int T,L;
    int en;
    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            cin >> T >> L;
            for(j = 0;j < T;j++)
            {
                cin >> A[j];
            }
            sort(A,A+T);
            reverse(A,A+T);
            en = T - 1;
            sum = 0;
            for(j = 0;j <= en;j++)
            {
                if(A[j] + A[en] <= L)
                    en--;
                sum++;
            }
            if(i != 0)
                cout << endl;
            cout << sum << endl;

        }
    }
}

