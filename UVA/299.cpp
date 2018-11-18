#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
int A[10000];
using namespace std;
int main()
{
    int SZ,P,i,j,k;
    double t;
    string L,M,a,b,c,d;
    int even,odd,evans;
    int trash;
    int N,T;
    cin >> N;
    int ans;
    for(i = 0;i < N;i++)
    {
        cin >> T;
        ans = 0;
        for(j = 0;j < T;j++)
        {
            cin >> A[j];
        }
        for(j = T;j >= 0;j--)
        {
            for(k = 0;k < j - 1;k++)
            {
                if(A[k] > A[k + 1])
                {
                    swap(A[k],A[k + 1]);
                    ans++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n",ans);
    }
}

