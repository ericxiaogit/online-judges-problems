#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
int A[1005];
int main()
{
    //string a;
    int num,N,i,how,temp,nows,j,a,big,print,ans;
    while(cin >> N)
    {
        ans = 0;
        for(i = 0;i < N;i++)
        {
            cin >> A[i];
        }
        for(i = N - 1;i > 0;i--)
        {
            for(j = 0;j < i;j++)
            {
                if(A[j] > A[j + 1])
                {
                    swap(A[j] , A[j+1]);
                    ans++;
                }
            }
        }
        cout << "Minimum exchange operations : " << ans << endl;
    }
}

