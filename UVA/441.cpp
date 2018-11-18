#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
#define SIZE 10000000
int A[15];

int main()
{
    //string a;
    int i,j,k;
    int x,y;
    int start_x,start_y;
    int T;
    long long int N,K,X;
    int a,b,c,d,e,f;
    int trash = 0;
    while(cin >> K)
    {
        if(K == 0) break;
        trash ++;
        if(trash != 1)
            cout << endl;
        for(i = 0;i < K;i++)
        {
            cin >> A[i];
        }
        sort(A,A+K);
        for(a = 0;a < K - 5;a++)
        {
            for(b = a + 1;b < K - 4;b++)
            {
                for(c = b + 1;c < K - 3;c++)
                {
                    for(d = c + 1;d < K - 2;d++)
                    {
                        for(e = d + 1;e < K - 1;e++)
                        {
                            for(f = e + 1;f < K;f++)
                            {
                                cout << A[a] << " " << A[b] << " " << A[c] << " " << A[d] << " " << A[e] << " " << A[f] <<endl;
                            }
                        }
                    }
                }
            }
        }
    }


}

