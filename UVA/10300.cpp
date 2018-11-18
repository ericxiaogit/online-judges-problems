#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
long long int A[1000+5][1000+5];
int main()
{
    int N;
    int i,j;
    int a,b,c,T;
    int sum;
    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            sum = 0;
            cin >> T;
            for(j = 0;j < T;j++)
            {
                cin >> a >> b >> c;
                sum += a * c;
            }
            cout<< sum << endl;
        }
    }
}

