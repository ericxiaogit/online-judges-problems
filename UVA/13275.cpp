#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
int A[3000 + 5];
bool  isLeapYear(int  year)
{
    if (year %  400  ==  0)
        return  true;
    else  if(year  %  100  ==  0)
        return  false;
    else  if(year  %  4  ==  0)
        return  true;
    else
        return  false;
}
int main()
{
    int sum,P,i,j,ll;
    double t;
    int even,odd,evans;
    int trash,temp;
    int W , N,M;
    int day,month,year,qy;
    trash = 0;
    int flag;
    A[0] = 0;
    for(i = 1;i <= 3000;i++)
    {
        if(isLeapYear(i) == true)
            A[i] = A[i-1] + 1;
        else
            A[i] = A[i-1];
    }
    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            cin >> day >> month >> year >> qy;
            cout << "Case " << i + 1 << ": ";
            if(day == 29 && month == 2)
            {
                cout << A[qy] - A[year] << endl;
            }
            else
                cout <<qy - year << endl;
        }


    }
}

