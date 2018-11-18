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
    int a,b;
    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            cin >> a >> b;
            if(a % 2 == 0)
                a++;
            if(b % 2 == 0)
                b--;
            cout << "Case " << i + 1 << ": " << (((b - a)/2) + 1) * (a + b) / 2 << endl;
        }
    }
}

