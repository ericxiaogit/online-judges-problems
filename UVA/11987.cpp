#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
int A[(100000 + 5)*2];
int number[(100000 + 5)*2];
int sum[(100000 + 5)*2];
int finds(int a)
{
    if(a != A[a])
    {
        A[a] = finds(A[a]);
    }
    return A[a];
}
int main()
{
    int n,m,i,j,k,temp,p,q,c,d;
    while(cin >> n >> m)
    {
        for(i = 1;i <= n;i++)
        {
            A[i] = i+n;
            A[i+n] = i+n;
            sum[i] = i;
            sum[i+n] = i;
            number[i] = 1;
            number[i + n] = 1;
        }
        for(i = 0;i < m;i++)
        {
            cin >> temp;
            if(temp == 1)
            {
                cin >> p >> q;
                c = finds(p);
                d = finds(q);
                if(c != d)
                {
                    A[d] = c;
                    number[c] += number[d];
                    sum[c] += sum[d];

                }
            }
            else if(temp == 2)
            {
                cin >> p >> q;
                c = finds(p);
                d = finds(q);
                if(c != d)
                {
                    A[p] = d;
                    number[d]++;
                    number[c]--;
                    sum[d] += p;
                    sum[c] -= p;
                }

            }
            else
            {
                cin >> p;
                c = finds(p);
                cout << number[c] << " " << sum[c] << endl;
            }
            for(j = 1;j <= 2*n;j++)
            {
                cout << A[j] << " ";
            }
            cout <<endl;
        }
    }
}

