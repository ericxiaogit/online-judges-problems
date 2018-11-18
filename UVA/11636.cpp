#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    int SZ,P,i,j,ll;
    double t;
    string L,M,a,b,c,d;
    int even,odd,evans;
    int trash,temp;
    int N;
    trash = 0;
    while(cin >> N)
    {
        if(N < 0) break;
        trash ++;
        temp = ceil(log2(N ));
        printf("Case %d: %d\n",trash,temp);
    }
}

