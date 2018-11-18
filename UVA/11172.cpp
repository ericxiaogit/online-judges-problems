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
            if(a > b)
                cout << ">" << endl;
            else if(a < b)
                cout << "<" << endl;
            else
                cout << "=" << endl;
        }
    }
}

