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
    int N;
    int a,b,c;
    int i;
    cin >> N;

    for(i = 0;i < N;i++)
    {
        cin >> a >> b >> c;
        cout << "Case " << i + 1 <<": ";
        if(a > b && b > c)
            cout << b << endl;
        else if(a > c && c > b)
            cout << c << endl;
        else if(b > a && a > c)
            cout << a << endl;
        else if(b > c && c > a)
            cout << c << endl;
        else if(c > a && a > b)
            cout << a << endl;
        else if(c > b && b > a)
            cout << b << endl;
    }

}

