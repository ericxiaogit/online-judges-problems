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
    while(1)
    {
        scanf("%d",&N);
        if(N == 0) break;
        flag = 0;
        for(i = 0;i < 105;i++)
        {
            A[i] = 0;
        }
        for(i = 0;i <N;i++)
        {
            scanf("%d",&temp);
            A[temp] ++;
        }
        for(i = 0;i < 101;i++)
        {
            if(A[i] != 0)
            {
                for(j = 0;j < A[i];j++)
                {
                    if(flag == 1)
                    {
                        //cout << " " << i;
                        printf(" %d",i);
                    }
                    else
                    {

                        printf("%d",i);
                        flag = 1;
                    }
                }
            }
        }
        cout << endl;
    }


}

