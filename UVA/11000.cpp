#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
long long int male[1000000];
long long int all[1000000];
long long int A(long long int year);

long long int M(long long int year)
{
    if(year == 0)
        return 0;
    else if(male[year] != 0)
        return male[year];
    else
    {
        male[year] = A(year - 1);
        return male[year];
    }

}
long long int A(long long int year)
{
    if(all[year] != 0)
        return all[year];
    else
    {
        all[year] = M(year) + M(year - 1) + 1;
        return all[year];
    }
}
int main()
{
    char p;
    //string a,t;
    all[0] = 1;
    male[0] = 0;
    long long int i,j;
    long long t,a,b;
    long long int N;
    int temp;

    while(cin >> N)
    {
        if(N == -1)
            break;
        cout << M(N) << " " << A(N) << endl;
    }

}



