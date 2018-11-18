#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
long long int G[1000000 + 10];
long long int A[1000000 + 10];
long long int N[1000000 + 10];
using namespace std;
int main()
{
    char p;
    //string a,t;
    long long int i,j;
    long long t,a,b;
    A[1] = 1;
    N[0] = 0;
    N[1] = 1;
    int temp;
    for(i = 1;i <= 1000000;i++)
    {
        for(j = i;j <= 1000000;j+=i)
        {
            G[j]++;
        }

    }
    for(i = 2;i <= 1000000;i++)
    {

        A[i] = A[i - 1] + G[A[i - 1]];
        if(A[i] <= 1000000)
            N[A[i]]+=1;
        N[i] += N[i - 1];
        //if(i < 10)
        //    cout << "i = " << i << " " << N[i] <<endl;
    }
    //cout << A[2] << endl;
    while(cin >> t)
    {
        for(i = 0;i < t;i++)
        {
            cin >> a >> b;
            cout << "Case " << i + 1 << ": ";
            cout << N[b] - N[a - 1] << endl;
        }
    }

}



