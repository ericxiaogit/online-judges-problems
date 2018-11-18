#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
int A[1000 + 5];
int M[100];
int ans[100];
int main()
{
    int SZ,P,i,j,k  ;
    double t;
    int even,odd,evans;
    int trash,temp;
    int N;
    trash = 0;
    int flag;
    int alen,blen,clen;
    int sum;
    SZ = 0;
    while(cin >> N)
    {
        if(N == 0) break;
        SZ++;
        for(i = 0;i < N;i++)
        {
            cin >> A[i];
        }
        cin >> P;
        for(i = 0;i < P;i++)
        {
            cin >> M[i];
        }
        for(i = 0;i < N;i++)
        {
            for(j = i+1;j < N;j++)
            {
                sum = A[i] + A[j];
                for(k = 0;k < P;k++)
                {
                    if(ans[k] == 0 || abs(M[k] - sum) < abs(M[k] - ans[k]))
                        ans[k] = sum;
                }
            }
        }
        cout << "Case " << SZ << ":" <<endl;
        for(i = 0;i < P;i++)
        {
            printf("Closest sum to %d is %d.\n",M[i],ans[i]);
        }


    }
}

