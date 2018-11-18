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
    char p;
    //string a,t;
    long long int i,j;
    long long c,a,b;
    int N,M;
    int temp;

    while(cin >> a >> b >> c)
    {
        if(a == b & b == c)
        {
            cout << '*' << endl;
        }
        else if(a == b && b != c)
            cout << 'C' << endl;
        else if(a == c && b != c)
            cout << 'B' << endl;
        else
            cout <<'A' << endl;
    }

}



