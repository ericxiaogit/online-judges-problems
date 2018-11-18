#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
int A[100000 + 5];
int main()
{
    int i,ans;
    int high,low,mid,last;
    int a,b;
    for(i = 1;i <= 316;i++)
    {
        A[i*i] ++;
    }
    for(i = 1;i < 100000 + 5;i++)
    {
        A[i] += A[i - 1];
    }
    while(cin >>a >> b)
    {
        if(a == 0 && b == 0) break;
        cout << A[b] - A[a - 1] << endl;
    }
}

