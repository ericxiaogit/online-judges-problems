#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
int A[100000 + 10000];
int main()
{
    int sum,P,i,j,ll;
    double t;
    int even,odd,evans;
    int trash,temp;
    int W , N,M;
    trash = 0;
    int flag;
    while(cin >> N)
    {
        for(i = 0;i <N;i++)
        {
            cin >> M >> W;
            for(j = 0;j < M;j++)
            {
                cin >> A[j];
            }
            sort(A,A+M);
            sum = 0;
            flag = 0;
            for(j = 0;j < M;j++)
            {
                //cout << j << " " << sum << endl;
                sum += A[j];
                if(sum > W)
                {
                    flag = 1;
                    break;
                }

            }
            if(flag == 1)
                cout << j <<endl;
            else
                cout << M << endl;
        }
    }
}

