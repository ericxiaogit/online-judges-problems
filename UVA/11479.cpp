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

    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            cin >> a >> b >> c;
            if(a > b)
                swap(a,b);
            if(b > c)
                swap(b,c);
            if(a > b)
                swap(a,b);
            cout << "Case " << i+1 << ": ";
            if(a <= 0 || b <= 0 || c <= 0)
                cout <<"Invalid" << endl;
            else if(a == b && b == c)
                cout << "Equilateral" << endl;
            else if(a + b <= c)
                cout << "Invalid" << endl;
            else if(a == b || b == c)
                cout <<  "Isosceles" << endl;
            else
                cout << "Scalene" << endl;

        }
    }

}



