#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
    long long int N;
    long long int i,a,b,c,d,temp,j,big,K;
    K = 0;

    while(cin >> K)
    {
        for(i = 0;i < K;i++)
        {
            cin >>N;
            temp = sqrt(N * 2) - 1;
            while(1)
            {
                temp ++;
                if(temp * (temp + 1) > N * 2) break;
            }
            cout << temp - 1 << endl;
        }
    }


}

